/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:26 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/15 10:25:05 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
}	t_mlx_data;

int	main(int argc, const char *argv[])
{
	// MAPの読み込み
	// -------MAPのエラーチェック-----------
	// ①0 1 C E Pのみで構成されている。
	// ②P Eはそれぞれ1つのみ。
	// ③Cは1つ以上
	// ④MAPが長方形であること
	// ⑤MAPは1で囲まれている必要がある。
	// ⑥有効なゲームかを確認する必要はない
	// ⑦MAPファイルにエラーがあった場合、綺麗な形で終了し、エラーごとに任意のメッセージを出力する。
	// -------MAPをグラフィックに出力-----------
	// ①画像をウィンドウに出力する
	// ②別のウィンドウへの切り替え、最小化がスムーズであること
	// ③ESCを押すと、ウィンドウが消え、綺麗な形でプログラムが終了する。
	//-------ゲーム開始-----------
	// ①コレクションアイテムを集め、最短距離で終了することを目的とする
	// ②移動は、W、A、S、Dキー
	// ③上下左右の4方向に動ける
	// ④プレイヤーが壁の中に入っていけない
	// ⑤一手ごとに、現在の移動回数をシェルに表示する

	// t_mlx_data	vars;
	t_map		*map;
	size_t		i;

	if (argc != 2)
		exit(1);
	map = load_map((char *)argv[1]);
	check_valid_map(map);
	fill_in_map(map);
	i = 0;
	while (i < map->count_column)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
	ft_printf("count_column:		%d\n", map->count_column);
	ft_printf("count_row:		%d\n", map->count_row);
	ft_printf("count_exit:		%d\n", map->count_exit);
	ft_printf("count_collection:	%d\n", map->count_collection);
	ft_printf("count_player:		%d\n", map->count_player);
	free(map->map_element);
	free(map);
	i = 0;
	while (i < map->count_column)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map[i]);
	free(map->map);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "./so_long");
	// mlx_hook(vars.win, 2, 1L << 2, close, &vars);
	// mlx_loop(vars.mlx);
	system("leaks so_long");
	return (0);
}
