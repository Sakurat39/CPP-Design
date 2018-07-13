
#pragma once

namespace chessDom {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading::Tasks;
	using namespace System::Xml;
	using namespace System::Xaml;
	struct Position
	{
		int row;
		int conlum;
	};
	enum ChessCorlor {
		Red = 0,
		Black=1
	};
	enum chesstype {
		bossblack = 0,
		guard = 1,
		minister = 2,
		hourse = 3,
		car = 4,
		fire = 5,
		solider = 6,
		nazo = 2,
		bossred =7,
	};
	class chessman {
	private:
		int color;
		int type;
	public:
		chessman(ChessCorlor colorm, chesstype ct) {
			color = colorm;
			type = ct;
		}
		int gettype() {
			return type;
		}
		int getcolor() {
			return color;
		}
	};
	
	
	class kiban	 {
	private:
		int redbossr, redbossc;
		int blackbossr, blackbossc;
		static kiban* kobj;
		chessman *chessarr[10][9];
		kiban() { 
			
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					chessarr[i][j]= 0;
				}
			  
			}

			//初始化棋盘
			initkiban();
		}
		
		
		void initkiban() {
			//black
			chessarr[0][0] = new chessman(Black, car);
			chessarr[0][1] = new chessman(Black, hourse);
			chessarr[0][2] = new chessman(Black, nazo);
			chessarr[0][3] = new chessman(Black, guard);
			chessarr[0][4] = new chessman(Black, bossblack);
			chessarr[0][5] = new chessman(Black, guard);
			chessarr[0][6] = new chessman(Black, nazo);
			chessarr[0][7] = new chessman(Black, hourse);
			chessarr[0][8] = new chessman(Black, car);

			chessarr[2][1]= new chessman(Black, fire);
			chessarr[2][7] = new chessman(Black, fire);

			chessarr[3][0] = new chessman(Black, solider);
			chessarr[3][2] = new chessman(Black, solider);
			chessarr[3][4] = new chessman(Black, solider);
			chessarr[3][6] = new chessman(Black, solider);
			chessarr[3][8] = new chessman(Black, solider);
			//red
			chessarr[9][0] = new chessman(Red, car);
			chessarr[9][1] = new chessman(Red, hourse);
			chessarr[9][2] = new chessman(Red, minister);
			chessarr[9][3] = new chessman(Red, guard);
			chessarr[9][4] = new chessman(Red, bossred);
			chessarr[9][5] = new chessman(Red, guard);
			chessarr[9][6] = new chessman(Red, minister);
			chessarr[9][7] = new chessman(Red, hourse);
			chessarr[9][8] = new chessman(Red, car);

			chessarr[7][1] = new chessman(Red, fire);
			chessarr[7][7] = new chessman(Red, fire);
			chessarr[6][0] = new chessman(Red, solider);
			chessarr[6][2] = new chessman(Red, solider);
			chessarr[6][4] = new chessman(Red, solider);
			chessarr[6][6] = new chessman(Red, solider);
			chessarr[6][8] = new chessman(Red, solider);
			redbossr = 9; redbossc = 4;
			blackbossr = 0; blackbossc = 4;
		}
		kiban(const kiban&);
		kiban& operator=(const kiban&);

	public:
		bool isbossbefaced() {
			for (int i = blackbossr + 1; i < 10; i++) {
				if (chessarr[i][blackbossc] == 0) continue;
				if (chessarr[i][blackbossc]->gettype() != bossred)
					return false; else return true;
			}
			return false;
		}
		bool ifbossbethreadened(ChessCorlor cc) {
			if (cc == Red) { //卒\炮\车\马
				//卒  左右上下是否有敌方卒
				if (redbossc - 1>=0 && chessarr[redbossr][redbossc - 1] != 0 && chessarr[redbossr][redbossc - 1]->gettype()==solider && chessarr[redbossr][redbossc - 1] ->getcolor()==Black) {
					return true;
				}
				if (chessarr[redbossr][redbossc +1] != 0 && chessarr[redbossr][redbossc +1]->gettype() == solider && chessarr[redbossr][redbossc+1]->getcolor() == Black) {
					return true;
				}
				if (redbossr - 1>=0 && chessarr[redbossr-1][redbossc] != 0 && chessarr[redbossr-1][redbossc]->gettype() == solider && chessarr[redbossr-1][redbossc]->getcolor() == Black) {
					return true;
				}
				if (redbossr + 1<10 && chessarr[redbossr+1][redbossc] != 0 && chessarr[redbossr + 1][redbossc]->gettype() == solider && chessarr[redbossr + 1][redbossc]->getcolor() == Black) {
					return true;
				}
				//车
				for (int i = redbossr - 1; i >= 0; i--) {
					if (chessarr[i][redbossc] == 0) continue;
					if (chessarr[i][redbossc]->gettype() == car && chessarr[i][redbossc]->getcolor() == Black) return true; else break;
				}
				//down
				for (int i = redbossr + 1; i < 10; i++) {
					if (chessarr[i][redbossc] == 0) continue;
					if (chessarr[i][redbossc]->gettype() == car && chessarr[i][redbossc]->getcolor() == Black) return true; else break;
				}
				//left
				for (int i = redbossc - 1; i >= 0; i--) {
					if (chessarr[redbossr][i] == 0) continue;
					if (chessarr[redbossr][i]->gettype() == car && chessarr[redbossr][i]->getcolor() == Black) return true; else break;
				}
				//right
				for (int i = redbossc + 1; i <9; i++) {
					if (chessarr[redbossr][i] == 0) continue;
					if (chessarr[redbossr][i]->gettype() == car && chessarr[redbossr][i]->getcolor() == Black) return true; else break;
				}

				//马
				if ( redbossr - 2>=0 && chessarr[redbossr - 2][redbossc + 1] != 0 && chessarr[redbossr - 1][redbossc] == 0 && chessarr[redbossr - 2][redbossc+1]->gettype()==hourse && chessarr[redbossr - 2][redbossc+1]->getcolor()==Black) { //右上角
					return true;
				}
				if ( redbossr - 2 >= 0 && chessarr[redbossr - 2][redbossc - 1] != 0 && chessarr[redbossr - 1][redbossc ] == 0 && chessarr[redbossr - 2][redbossc - 1]->gettype() == hourse && chessarr[redbossr - 2][redbossc - 1]->getcolor() == Black) { //左上角
					return true;
				}
				if (redbossr+2 <10 && redbossc - 1>=0 && chessarr[redbossr + 2][redbossc - 1] != 0 && chessarr[redbossr + 1][redbossc] == 0 && chessarr[redbossr + 2][redbossc - 1]->gettype() == hourse && chessarr[redbossr +2][redbossc - 1]->getcolor() == Black) { //右下角
					return true;
				}
				if (redbossr+2 <10 && chessarr[redbossr + 2][redbossc + 1]!=0 && chessarr[redbossr + 1][redbossc] == 0 && chessarr[redbossr + 2][redbossc +1]->gettype() == hourse && chessarr[redbossr + 2][redbossc + 1]->getcolor() == Black) { //左下角
					return true;
				}


				if (redbossc - 2>=0 && redbossr - 1>=0 && chessarr[redbossr - 1][redbossc - 2]!=0 && chessarr[redbossr][redbossc - 1] == 0 && chessarr[redbossr -1][redbossc -2]->gettype() == hourse && chessarr[redbossr -1][redbossc -2]->getcolor() == Black) { //z上角
					return true;
				}
				if (redbossr - 1>=0 && chessarr[redbossr - 1][redbossc + 2]!=0 && chessarr[redbossr][redbossc + 1] == 0 && chessarr[redbossr - 1][redbossc + 2]->gettype() == hourse && chessarr[redbossr - 1][redbossc + 2]->getcolor() == Black) { //y上角
					return true;
				}
				if (redbossc - 2>=0 && chessarr[redbossr + 1][redbossc - 2]!=0 && redbossr + 1<10 && chessarr[redbossr][redbossc - 1] == 0 && chessarr[redbossr + 1][redbossc - 2]->gettype() == hourse && chessarr[redbossr + 1][redbossc - 2]->getcolor() == Black) { //右下角
					return true;
				}
				if (chessarr[redbossr + 1][redbossc + 2]!=0 && redbossr + 1<10 && chessarr[redbossr][redbossc + 1] == 0 && chessarr[redbossr + 1][redbossc +2]->gettype() == hourse && chessarr[redbossr + 1][redbossc + 2]->getcolor() == Black) { //左下角
					return true;
				}


				//炮
				int t= redbossr - 1, d= redbossr + 1, l= redbossc - 1, r= redbossc + 1;
				//1在不隔子范围内同车
				for (int t = redbossr - 1; t>= 0; t--) {

					if (chessarr[t][redbossc] != 0) break;
					
				}
				//down
				for (int d = redbossr + 1; d < 10; d++) {

					if (chessarr[d][redbossc] != 0) break;
				}
				//left
				for (int l = redbossc - 1; l >= 0; l--) {

					if (chessarr[redbossr][l] != 0) break;
					
				}
				//right
				for (int r = redbossc + 1; r <9; r++) {

					if (chessarr[redbossr][r] != 0) break;
				
				}

				//2寻找吃子
				bool hasmiddlechess = false;
				//上
				for (int up = t ; up >= 0; up--) {

					if (chessarr[up][redbossc] != 0) {
						if (hasmiddlechess) {
							if (chessarr[up][redbossc]->getcolor() == Black && chessarr[up][redbossc]->gettype() == fire) return true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}

				}
				hasmiddlechess = false;
				//下
				for (int down = d ; down < 10; down++) {

					if (chessarr[down][redbossc] != 0) {
						if (hasmiddlechess) {
							if (chessarr[down][redbossc]->getcolor() == Black && chessarr[down][redbossc]->gettype() == fire) return true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}

				}
				hasmiddlechess = false;
				//左
				for (int left = l ; l >= 0; l--) {

					if (chessarr[redbossr][left] != 0) {
						if (hasmiddlechess) {
							if (chessarr[redbossr][left]->getcolor() == Black && chessarr[redbossr][left]->gettype() == fire) return true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}
				}
				//右
				hasmiddlechess = false;
				for (int right = r ; right <9; right++) {

					if (chessarr[redbossr][right] != 0) {
						if (hasmiddlechess) {
							if (chessarr[redbossr][right]->getcolor() == Black && chessarr[redbossr][right]->gettype() == fire) return true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}
				}
			}
			else {
				if (cc == Black) { //卒\炮\车\马
								//卒  左右上下是否有敌方卒
					if (chessarr[blackbossr][blackbossc - 1] != 0 && chessarr[blackbossr][blackbossc - 1]->gettype() == solider && chessarr[blackbossr][blackbossc - 1]->getcolor() ==Red) {
						return true;
					}
					if (chessarr[blackbossr][blackbossc + 1] != 0 && chessarr[blackbossr][blackbossc + 1]->gettype() == solider && chessarr[blackbossr][blackbossc + 1]->getcolor() == Red) {
						return true;
					}
					if ( blackbossr - 1>0 && chessarr[blackbossr - 1][blackbossc] != 0 && chessarr[blackbossr - 1][blackbossc] != 0 && chessarr[blackbossr - 1][blackbossc]->gettype() == solider && chessarr[blackbossr - 1][blackbossc]->getcolor() == Red) {
						return true;
					}
					if (blackbossr + 1<10 && chessarr[blackbossr + 1][blackbossc] != 0 && chessarr[blackbossr + 1][blackbossc] != 0 && chessarr[blackbossr + 1][blackbossc]->gettype() == solider && chessarr[blackbossr + 1][blackbossc]->getcolor() == Red) {
						return true;
					}
					//车
					for (int i = blackbossr - 1; i >= 0; i--) {
						if (chessarr[i][blackbossc] == 0) continue;
						if (chessarr[i][blackbossc]->gettype() == car && chessarr[i][blackbossc]->getcolor() == Red) return true; else break;
					}
					//down
					for (int i = blackbossr + 1; i < 10; i++) {
						if (chessarr[i][blackbossc] == 0) continue;
						if (chessarr[i][blackbossc]->gettype() == car && chessarr[i][blackbossc]->getcolor() == Red) return true; else break;
					}
					//left
					for (int i = blackbossc - 1; i >= 0; i--) {
						if (chessarr[blackbossr][i] == 0) continue;
						if (chessarr[blackbossr][i]->gettype() == car && chessarr[blackbossr][i]->getcolor() == Red) return true; else break;
					}
					//right
					for (int i = blackbossc + 1; i <9; i++) {
						if (chessarr[blackbossr][i] == 0) continue;
						if (chessarr[blackbossr][i]->gettype() == car && chessarr[blackbossr][i]->getcolor() == Red) return true; else break;
					}

					//马
					if (blackbossr - 2 >= 0 && chessarr[blackbossr - 2][blackbossc + 1] != 0 && chessarr[blackbossr - 1][blackbossc] == 0 && chessarr[blackbossr - 2][blackbossc + 1]->gettype() == hourse && chessarr[blackbossr - 2][blackbossc + 1]->getcolor() == Red) { //右上角
						return true;
					}
					if ( blackbossr - 2 >= 0 && chessarr[blackbossr - 2][blackbossc - 1] != 0 && chessarr[blackbossr - 1][blackbossc] == 0 && chessarr[blackbossr - 2][blackbossc - 1]->gettype() == hourse && chessarr[blackbossr - 2][blackbossc - 1]->getcolor() == Red)
 { //左上角
						return true;
					}
					if ( blackbossr + 2 <10 && chessarr[blackbossr + 2][blackbossc - 1] != 0 && chessarr[blackbossr + 1][blackbossc] == 0 && chessarr[blackbossr + 2][blackbossc - 1]->gettype() == hourse && chessarr[blackbossr + 2][blackbossc - 1]->getcolor() == Red) { //右下角
						return true;
					}
					if ( blackbossr + 2 <10 && chessarr[blackbossr + 2][blackbossc + 1] != 0 && chessarr[blackbossr + 1][blackbossc] == 0 && chessarr[blackbossr + 2][blackbossc + 1]->gettype() == hourse && chessarr[blackbossr + 2][blackbossc + 1]->getcolor() == Red) { //左下角
						return true;
					}


					if (blackbossr - 1>=0 && chessarr[blackbossr - 1][blackbossc - 2]!=0 && chessarr[blackbossr][blackbossc - 1] == 0 && chessarr[blackbossr - 1][blackbossc - 2]->gettype() == hourse && chessarr[blackbossr - 1][blackbossc - 2]->getcolor() == Red) { //z上角
						return true;
					}
					int u = blackbossr;
					int k = blackbossc;
					if (blackbossr - 1>=0 && chessarr[blackbossr - 1][blackbossc + 2]!=0 && chessarr[blackbossr][blackbossc + 1] == 0 && chessarr[blackbossr - 1][blackbossc + 2]->gettype() == hourse && chessarr[blackbossr - 1][blackbossc + 2]->getcolor() == Red) { //y上角
						return true;
					}
					if (blackbossc - 2>=0 && chessarr[blackbossr + 1][blackbossc - 2]!=0 && blackbossr + 1<10 && chessarr[blackbossr][blackbossc - 1] == 0 && chessarr[blackbossr + 1][blackbossc - 2]->gettype() == hourse && chessarr[blackbossr + 1][blackbossc - 2]->getcolor() == Red) { //右下角
						return true;
					}
					if (chessarr[blackbossr + 1][blackbossc + 2]!=0 && blackbossr + 1<10 && chessarr[blackbossr][blackbossc + 1] == 0 && chessarr[blackbossr + 1][blackbossc + 2]->gettype() == hourse && chessarr[blackbossr + 1][blackbossc + 2]->getcolor() == Red) { //左下角
						return true;
					}


					//炮
					int t= blackbossr - 1, d= blackbossr + 1, l= blackbossc - 1, r= blackbossc + 1;
					//1在不隔子范围内同车
					for (int t = blackbossr - 1; t >= 0; t--) {

						if (chessarr[t][blackbossc] != 0) break;

					}
					//down
					for (int d = blackbossr + 1; d < 10; d++) {

						if (chessarr[d][blackbossc] != 0) break;
					}
					//left
					for (int l = blackbossc - 1; l >= 0; l--) {

						if (chessarr[blackbossr][l] != 0) break;

					}
					//right
					for (int r = blackbossc + 1; r <9; r++) {

						if (chessarr[blackbossr][r] != 0) break;

					}

					//2寻找吃子
					bool hasmiddlechess = false;
					//上
					for (int up = t ; up >= 0; up--) {

						if (chessarr[up][blackbossc] != 0) {
							if (hasmiddlechess) {
								if (chessarr[up][blackbossc]->getcolor() == Red && chessarr[up][blackbossc]->gettype() == fire) return true;
								hasmiddlechess = false;
								break;
							}
							else {
								hasmiddlechess = true;
							}
						}

					}
					hasmiddlechess = false;
					//下
					for (int down = d ; down < 10; down++) {

						if (chessarr[down][blackbossc] != 0) {
							if (hasmiddlechess) {
								if (chessarr[down][blackbossc]->getcolor() == Red && chessarr[down][blackbossc]->gettype() == fire) return true;
								hasmiddlechess = false;
								break;
							}
							else {
								hasmiddlechess = true;
							}
						}

					}
					hasmiddlechess = false;
					//左
					for (int left = l; l >= 0; left--) {

						if (chessarr[blackbossr][left] != 0) {
							if (hasmiddlechess) {
								if (chessarr[blackbossr][left]->getcolor() == Red && chessarr[blackbossr][left]->gettype() == fire) return true;
								hasmiddlechess = false;
								break;
							}
							else {
								hasmiddlechess = true;
							}
						}
					}
					//右
					hasmiddlechess = false;
					for (int right = r; right <9; right++) {
						//MessageBox::Show(blackbossr.ToString()+":"+ right.ToString());
						if (chessarr[blackbossr][right] != 0) {
							if (hasmiddlechess) {
								if (chessarr[blackbossr][right]->getcolor() == Red && chessarr[blackbossr][right]->gettype() == fire) 
									return true;
								hasmiddlechess = false;
								break;
							}
							else {
								hasmiddlechess = true;
							}
						}
					}
				}
			}
		}
		
		int move(int sr, int sc, int er, int ec) {  //返回true代表游戏结束
			if (chessarr[sr][sc] == 0) return 0;
			if (chessarr[sr][sc]->gettype() == bossred) { redbossc = ec; redbossr = er; }
			if (chessarr[sr][sc]->gettype() == bossblack) { blackbossc = ec; blackbossr = er; }
			if (chessarr[er][ec] == 0) { //移动到空位
				chessarr[er][ec] = chessarr[sr][sc];
				chessarr[sr][sc] = 0;
				if (isbossbefaced() == true) 
					return 1;

				
				bool thread = ifbossbethreadened(Red);
				if (thread) return 2;
				thread = ifbossbethreadened(Black);
				if (thread) return 3;
				return 0;
			}
			else {
				if (chessarr[er][ec]->gettype() == bossblack || chessarr[er][ec]->gettype() == bossred) {
					return 1;
				}
				
				else {
					
					chessarr[er][ec] = chessarr[sr][sc];
					chessarr[sr][sc] = 0;

					if (isbossbefaced() == true) return 1;
					bool thread = ifbossbethreadened(Red);
					if (thread) return 2;
					thread = ifbossbethreadened(Black);
					if (thread) return 3;
					return 0;
				}
			}
		}
		bool isEmptyposition(int r, int b) {
			if (chessarr[r][b] == 0) return true;
			else return false;
		}
		bool canbeclick[10][9];
		static kiban* getInstance() {
			if (kobj == 0) {
				kobj = new kiban();
			}
			return kobj;
		}
		bool isCanMove(ChessCorlor cc,Position po) {
			if (chessarr[po.row][po.conlum] == 0) return false;
			if (chessarr[po.row][po.conlum]->getcolor() == cc) return true;
			return false;
		}

		ChessCorlor getcolor(int r, int y) {
			return ((ChessCorlor)chessarr[r][y]->getcolor());
		}
		void setcanclicklist(ChessCorlor cc) {
			  //0:未选中棋子状态下刷新可选择位置
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (chessarr[i][j] != 0 && (chessarr[i][j]->getcolor()) == cc) {
							canbeclick[i][j] = true;
						}
						else {
							canbeclick[i][j] = false;
						}
					}
				}
			
			
		}
		void resetkiban() {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					chessarr[i][j] = 0;
				}

			}

			//初始化棋盘
			initkiban();
		}
		void setcanclicklist() {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					canbeclick[i][j] = false;
				}
			}
		}
		void setcanclicklist(int r, int c) {  //选中了某个棋子状态下进行可选择列表刷新
			if (kiban::getInstance()->chessarr[r][c] == 0) return;
			ChessCorlor cc =(ChessCorlor) chessarr[r][c]->getcolor();
			setcanclicklist(cc); //设置同颜色可选
			//设置选择棋子的可移动范围
			//^^^^^^^^^^^^^^^^^^^^^^^^^^
			chesstype ct =(chesstype)chessarr[r][c]->gettype();
			switch (ct)
			{
			case chessDom::bossred:
			{
				//left
				if (c != 3) {
					canbeclick[r][c - 1] = true;
				}
				//right
				if (c != 5) {
					canbeclick[r][c + 1] = true;
				}
				//top
				if (r != 7) {
					canbeclick[r-1][c] = true;
				}
				//below
				if (r != 9) {
					canbeclick[r + 1][c] = true;
				}
			}
				break;
			case chessDom::bossblack:
			{
				//left
				if (c != 3) {
					canbeclick[r][c - 1] = true;
				}
				//right
				if (c != 5) {
					canbeclick[r][c + 1] = true;
				}
				//top
				if (r != 0) {
					canbeclick[r -1][c] = true;
				}
				//below
				if (c != 2) {
					canbeclick[r + 1][c] = true;
				}
			}
				break;
			case chessDom::guard:
			{
				ChessCorlor cc = (ChessCorlor)chessarr[r][c]->getcolor();
				if (cc == Red) {  //红棋士
					if (c + 1 <= 5 && r - 1 >= 7) { //右上角
						canbeclick[r - 1][c + 1] = true;
					}
					if (c - 1 >= 3 && r - 1 >= 7) { //左上角
						canbeclick[r - 1][c - 1] = true;
					}
					if (c + 1 <= 5 && r + 1 <=9) { //右下角
						canbeclick[r +1][c + 1] = true;
					}
					if (c - 1 >= 3 && r + 1 <= 7) { //左下角
						canbeclick[r + 1][c -1] = true;
					}
				}
				else {
					if (c + 1 <= 5 && r - 1 >=0) { //右上角
						canbeclick[r - 1][c + 1] = true;
					}
					if (c - 1 >= 3 && r - 1 >= 0) { //左上角
						canbeclick[r - 1][c - 1] = true;
					}
					if (c + 1 <= 5 && r + 1 <= 2) { //右下角
						canbeclick[r + 1][c + 1] = true;
					}
					if (c - 1 >= 3 && r + 1 <= 2) { //左下角
						canbeclick[r + 1][c -1] = true;
					}
				}
			}
				break;
			case chessDom::minister:
			{
				ChessCorlor cc = (ChessCorlor)chessarr[r][c]->getcolor();
				if (cc == Red) {  //红棋士
					if (c + 2 <= 8 && r - 2 >=5 && chessarr[r - 1][c+1]==0) { //右上角
						canbeclick[r - 2][c + 2] = true;
					}
					if (c - 2 >= 0 && r - 2 >= 5 && chessarr[r-1][c - 1] == 0) { //左上角
						canbeclick[r - 2][c - 2] = true;
					}
					if (c + 2 <= 8 && r + 2 <= 9 && chessarr[r + 1][c + 1] == 0) { //右下角
						canbeclick[r + 2][c + 2] = true;
					}
					if (c - 2 >= 0 && r + 2 <= 9 && chessarr[r+1][c- 1] == 0) { //左下角
						canbeclick[r + 2][c -2] = true;
					}
				}
				else {
					if (c + 2 <= 8 && r - 2 >=0 && chessarr[r - 1][c + 1] == 0) { //右上角
						canbeclick[r - 2][c + 2] = true;
					}
					if (c - 2 >= 0 && r - 2 >= 0 && chessarr[r - 1][c - 1] == 0) { //左上角
						canbeclick[r - 2][c - 2] = true;
					}
					if (c + 2 <= 8 && r + 2 <= 4 && chessarr[r + 1][c + 1] == 0) { //右下角
						canbeclick[r + 2][c + 2] = true;
					}
					if (c - 2 >= 0 && r + 2 <= 4 && chessarr[r + 1][c - 1] == 0) { //左下角
						canbeclick[r + 2][c - 2] = true;
					}
				}
			}
				break;
			case chessDom::hourse:
			{
				
					if (c + 1 <= 8 && r - 2 >= 0 && chessarr[r - 1][c] == 0) { //右上角
						canbeclick[r - 2][c + 1] = true;
					}
					if (c - 1 >= 0 && r - 2 >= 0 && chessarr[r - 1][c] == 0) { //左上角
						canbeclick[r - 2][c - 1] = true;
					}
					if (c + 1 <= 8 && r + 2 <= 9 && chessarr[r + 1][c] == 0) { //右下角
						canbeclick[r + 2][c + 1] = true;
					}
					if (c - 1 >= 0 && r + 2 <= 9 && chessarr[r + 1][c] == 0) { //左下角
						canbeclick[r + 2][c - 1] = true;
					}


					if (c + 2 <= 8 && r - 1 >= 0 && chessarr[r][c + 1] == 0) { //右上角
						canbeclick[r - 1][c + 2] = true;
					}
					if (c - 2 >= 0 && r - 1 >= 0 && chessarr[r][c - 1] == 0) { //左上角
						canbeclick[r - 1][c - 2] = true;
					}
					if (c + 2 <= 8 && r + 1 <= 9 && chessarr[r][c + 1] == 0) { //右下角
						canbeclick[r + 1][c + 2] = true;
					}
					if (c - 2 >= 0 && r + 1 <= 9 && chessarr[r][c - 1] == 0) { //左下角
						canbeclick[r + 1][c - 2] = true;
					}
				
			}
				break;
			case chessDom::car:
				//车往上
			{
				for (int i = r - 1; i >= 0; i--) {
					canbeclick[i][c] = true;
					if (chessarr[i][c] != 0) break;
				}
			    //down
				for (int i = r + 1; i < 10; i++) {
					canbeclick[i][c] = true;
					if (chessarr[i][c] != 0) break;
				}
				//left
				for (int i = c - 1; i >= 0; i--) {
					canbeclick[r][i] = true;
					if (chessarr[r][i] != 0) break;
				}
				//right
				for (int i = c +1; i <9; i++) {
					canbeclick[r][i] = true;
					if (chessarr[r][i] != 0) break;
				}
			}
				break;
			case chessDom::fire:
			{
				
				//1在不隔子范围内同车
				for (int up = r - 1; up >= 0; up--) {
					
					if (chessarr[up][c] != 0) break;
					canbeclick[up][c] = true;
				}
				//down
				for (int down = r + 1; down < 10; down++) {
					
					if (chessarr[down][c] != 0) break;
					canbeclick[down][c] = true;
				}
				//left
				for (int l = c - 1; l >= 0; l--) {
					
					if (chessarr[r][l] != 0) break;
					canbeclick[r][l] = true;
				}
				//right
				for (int right = c + 1; right <9; right++) {
					
					if (chessarr[r][right] != 0) break;
					canbeclick[r][right] = true;
				}

				//2寻找吃子
				bool hasmiddlechess = false;
				//上
				for (int up = r - 1; up >= 0; up--) {
					
					if (chessarr[up][c] != 0) {
						if(hasmiddlechess){
							canbeclick[up][c] = true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}
					
				}
				hasmiddlechess = false;
				//下
				for (int down = r + 1; down < 10; down++) {
					
					if (chessarr[down][c] != 0) {
						if (hasmiddlechess) {
							canbeclick[down][c] = true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}
				
				}
				hasmiddlechess = false;
				//左
				for (int l = c - 1; l >= 0; l--) {
					
					if (chessarr[r][l] != 0) {
						if (hasmiddlechess) {
							canbeclick[r][l] = true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}
				}
				//右
				hasmiddlechess = false;
				for (int right = c + 1; right <9; right++) {
					
					if (chessarr[r][right] != 0) {
						if (hasmiddlechess) {
							canbeclick[r][right] = true;
							hasmiddlechess = false;
							break;
						}
						else {
							hasmiddlechess = true;
						}
					}
				}
			}
				break;
			case chessDom::solider:
			{
				if (cc == Red) {
					//up
					if (r != 0) {
						canbeclick[r - 1][c] = true;
					}

					if (r < 5) {
						//left
						if (c != 0) {
							canbeclick[r][c - 1] = true;
						}
						//right
						if (c != 8) {
							canbeclick[r][c + 1] = true;
						}
					}
					
				}else{
				
					//up
					if (r != 9) {
						canbeclick[r + 1][c] = true;
					}

					if (r >=5) {
						//left
						if (c != 0) {
							canbeclick[r][c - 1] = true;
						}
						//right
						if (c != 8) {
							canbeclick[r][c + 1] = true;
						}
					}
				}
			}
				break;
			default:
				break;
			}
		}
		
	};
	kiban* kiban::kobj = new kiban;
}
namespace Compitition {
	using namespace System::Collections::Generic;
	using namespace chessDom;
	ref class step {
	public:
		
		int startr1, startc1;
		int endr2, endc2;
		Image^ sima = nullptr;
		Image^ eima = nullptr;
		ChessCorlor co;
		step(int sr, int sc, int er, int ec, ChessCorlor cc,Image^ imas,Image^ imae) {
			startr1 = sr;
			startc1 = sc;
			endr2 = er;
			endc2 = ec;
			co = cc;
			sima = imas;
			eima = imae;
		}
	};
	ref class fright{
	public:
		DateTime^ dt;
		List<step^> ^steps = gcnew List<step^>();
		fright() {
			dt = DateTime::Now;
		}
		void addstep(int sr,int sc,int er,int ec,ChessCorlor cc, Image^ imas, Image^ imae) {
			steps->Add(gcnew step(sr,sc,er,ec,cc,imas,imae));
		}
    };
	
}