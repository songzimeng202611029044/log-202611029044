#include <stdio.h>
#include <math.h>
#include <windows.h>

// 设置文字颜色
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    float x, y;
    float t = 0;
    while (1)
    {
        system("cls"); //清屏
        for (y = 1.5f; y > -1.5f; y -= 0.1f)
        {
            for (x = -1.5f; x < 1.5f; x += 0.05f)
            {
                float scale = 1 + 0.1f * sin(t);
                float a = (x / scale)*(x / scale) + (y / scale)*(y / scale) - 1;
                if (a*a*a - (x / scale)*(x / scale)*(y / scale)*(y / scale)*(y / scale) <= 0)
                {
                    setColor(4); // 4 = 红色
                    printf("*");
                }
                else
                {
                    setColor(7); //7 = 默认白色
                    printf(" ");
                }
            }
            printf("\n");
        }
        setColor(4);
        printf("        I love you\n");
        setColor(7); //恢复白色
        t += 0.2f;
        Sleep(80); //跳动速度，数字越大越慢
    }
    return 0;
}
