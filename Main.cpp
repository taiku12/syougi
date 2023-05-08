# include <Siv3D.hpp> // OpenSiv3D v0.6.9


void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(Color{ 111, 84, 70 });
	const Texture TextureKoma{ U"C:/syogi/koma.png" };
	if (not TextureKoma)
	{
		Print << U"textureKoma is empty";
	}
	const Font font40{ 30,FileSystem::GetFolderPath(SpecialFolder::SystemFonts) + U"HGRGY.TTC" };
	//駒と数値の対応//
	Grid<int> bann =
	{
		{1,2,3,4,5,4,3,2,1},
		{0,6,0,0,0,0,0,7,0},
		{8,8,8,8,8,8,8,8,8},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{8,8,8,8,8,8,8,8,8},
		{0,7,0,0,0,0,0,6,0},
		{1,2,3,4,5,4,3,2,1}
	};
	while (System::Update())
	{
		//将棋盤の設定//
		int HABA;
		HABA = 450;
		int TILE;
		TILE = 50;
		Rect{ 400 - HABA / 2,300 - HABA / 2,HABA }.draw(Color(240, 184, 135));//RGBの順番//
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				Rect{ 400 - HABA / 2 + TILE * x,300 - HABA / 2 + TILE * y, TILE }.drawFrame(1, 1, Palette::Black);
			}
		}
		//自分//
		//歩の設置//
		
		const String hu = U"歩";
		for (int x = 0; x < 9; x++) {
			TextureKoma.scaled(0.1).drawAt(200+TILE*x, 400);
			font40(hu).draw(185+TILE*x, 385,Palette::Black);
		}
		//飛車角//

		const String hisya = U"飛";
		const String kaku = U"角";
		TextureKoma.scaled(0.1).drawAt(250 , 450);
		font40(hisya).draw(235, 435, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(550 , 450);
		font40(kaku).draw(535, 435, Palette::Black);

		//1行目//
		const String kyousya = U"香";
		const String keima = U"桂";
		const String ginn = U"銀";
		const String kinn = U"金";
		const String ou = U"王";
		TextureKoma.scaled(0.1).drawAt(200, 500);
		font40(kyousya).draw(185, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(250, 500);
		font40(keima).draw(235, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(300, 500);
		font40(ginn).draw(285,485 , Palette::Black);
		TextureKoma.scaled(0.1).drawAt(350, 500);
		font40(kinn).draw(335, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(400, 500);
		font40(ou).draw(385, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(450, 500);
		font40(kinn).draw(435, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(500, 500);
		font40(ginn).draw(485, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(550, 500);
		font40(keima).draw(535, 485, Palette::Black);
		TextureKoma.scaled(0.1).drawAt(600, 500);
		font40(kyousya).draw(585, 485, Palette::Black);

		//相手//
		//歩//

		
		for (int x = 0; x < 9; x++) {
			TextureKoma.scaled(0.1).flipped().drawAt(200 + TILE * x, 200);
			font40(hu).drawAt(200 + TILE * x, 200, Palette::Black);
		}
		//飛車角//

		
		TextureKoma.scaled(0.1).flipped().drawAt(250, 150);
		font40(hisya).draw(235, 135, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(550, 150);
		font40(kaku).draw(535, 135, Palette::Black);

		//1行目//
		const String gyoku = U"玉";
		TextureKoma.scaled(0.1).flipped().drawAt(200, 100);
		font40(kyousya).draw(185, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(250, 100);
		font40(keima).draw(235, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(300, 100);
		font40(ginn).draw(285, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(350, 100);
		font40(kinn).draw(335, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(400, 100);
		font40(gyoku).draw(385, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(450, 100);
		font40(kinn).draw(435, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(500, 100);
		font40(ginn).draw(485, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(550, 100);
		font40(keima).draw(535, 85, Palette::Black);
		TextureKoma.scaled(0.1).flipped().drawAt(600, 100);
		font40(kyousya).draw(585, 85, Palette::Black);

		//駒について//
		const Size size = bann.size();

		// 盤面と同じ大きさの二次元配列
		Grid<int> states(size);

		// 各マスの接続状況を管理するデータ構造
		DisjointSet<int32> ds{ states.num_elements() };



	}
}


