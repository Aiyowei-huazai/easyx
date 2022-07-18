
#include<graphics.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
using namespace std;

#define Max 200

struct Star
{
	double x;
	int y;
	double step;
	int color;
};

Star star[Max];

void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 50000 / 1000.0 + 1);
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

void MoveStar(int i)
{
	putpixel((int)star[i].x, star[i].y, 0);

	star[i].x += star[i].step;
	if (star[i].x > 640) InitStar(i);

	putpixel((int)star[i].x, star[i].y, star[i].color);
}

int main()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);

	for (int i = 0; i < Max; i++)
	{
		InitStar(i);
		star[i].x = rand() % 640;
	}
	while (!_kbhit())
	{
		for (int i = 0; i < Max; i++)
		{
			MoveStar(i);
			Sleep(20);
		}
	}

	closegraph();
	system("pause");
	return 0;
}