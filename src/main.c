/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:26 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/11 18:13:00 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int closed(int keycode, t_mlx_info *vars)
// {
// 	(void)keycode;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }
typedef struct s_map_info
{
	void	*mlx;
	void	*win;
}	t_map;

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

	// t_mlx_info	vars;

	char	*map;
	if (argc != 2)
		exit(1);
	map = load_map((char *)argv[1]);
	check_valid_map(map);
	ft_printf("%s", map);
	free(map);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// mlx_hook(vars.win, 2, 1L << 2, closed, &vars);
	// mlx_loop(vars.mlx);
	system("leaks so_long");
	return (0);
}
