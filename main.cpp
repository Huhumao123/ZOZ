#include<iostream>
#include<windows.h>
#define random(a,b) (rand()%(b-a)+a)
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
//Goint 1.0.4 (Goint 1.0.5 2021.12.2 HHM)
//
int main() {
	//初始化 
	srand((int)time(NULL));
	char map[40]={};
	char o0=' ';
	char o1='o';
	char line;
	char up=0;
	char upT=0;
	int score=-40;
	short int life=3;
	char protect=6;//游戏开始地图前6个字符必定是'_'防止玩家死亡 

	//保护: 防止一开始就死亡 
	for(int i=0;i<protect;i++){
		system("CLS");
		map[i]='_';
		cout<<o0<<"  time: "<<score<<"  life: "<<life<<endl<<o1;
		for(int i=1;i<40;i++){
			cout<<map[i];
		}
		score++;
		Sleep(20);
	}
	for(int i=protect;i<40;i++){
		system("CLS");
		line=random(0,20);
		if(line==1){
			map[i]='z';
		}
		else{
			map[i]='_';
		}
		cout<<o0<<"  time: "<<score<<"  life: "<<life<<endl<<o1;
		for(int i=1;i<40;i++){
			cout<<map[i];
		}
		score++;
		Sleep(20);
	}

	//主循环 
	while(true){
		system("CLS");
		line=random(0,20);
		for(int i=1;i<40;i++){
			map[i-1]=map[i];
		}
		if(line==1){
			map[39]='z';
		}
		else{
			map[39]='_';
		}
		if(KEY_DOWN(VK_SPACE)){
			up=3;
		}
		if(!KEY_DOWN(VK_SPACE)){
			if(up>0){
				up--;
			}
			else{
				up=0;
			}
		}
		if(up==0){
			o0=' ';
			o1='o';
			upT=0;
		}
		else{
			o0='o';
			o1=map[0];
			upT++;
		}
		if(upT>=7){
			o0=' ';
			o1='o';
			upT=0;
		}
		cout<<o0<<"  time: "<<score<<"  life: "<<life<<endl<<o1;
		for(int i=1;i<40;i++){
			cout<<map[i];
		}
		if(o1=='o'&&map[0]=='z'){
			life--;
		}
		if(life==0){
			break;
		}
		score++;
		Sleep(20);
	}
	system("CLS");
	cout<<"GAME OVER!  score: "<<score<<endl;
	cin>>score;//防止长摁跳跃而退出窗口 
}
