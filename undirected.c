#include<windows.h>
#include<math.h>
#define PI 3.14159265358979323846

double** randm(int rows, int cols){
                double** matrix = (double**)malloc(row * sizeof(double*));

                for (int i = 0; i < rows; i++)
                    matrix[i] = (double*)malloc(cols * sizeof(double));

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        matrix[i][j] =  2.0 * rand()/RAND_MAX;
                    }
                }

                return matrix;
            }

            double** mulmr(double coef, double **matrix, int rows, int cols){
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        matrix[i][j] = matrix[i][j] * coef;

                        if(matrix[i][j] > 1.0)
                        {
                            matrix[i][j] = 1;
                        } else matrix[i][j] = 0;
                        }
                }

                return matrix;
            }

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char ProgName[]="Ëàáîðàòîðíà ðîáîòà 3";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;

    WNDCLASS w; //ñîçäà¸ì ýêçåìïëÿð ñòðóêòóðû WNDCLASS

    w.lpszClassName=ProgName; //èìÿ ïðîãðàììû - îáúÿâëåíî âûøå
    w.hInstance=hInstance; //èäåíòèôèêàòîð òåêóùåãî ïðèëîæåíèÿ
    w.lpfnWndProc=WndProc; //óêàçàòåëü íà ôóíêöèþ îêíà
    w.hCursor=LoadCursor(NULL, IDC_ARROW); //çàãðóæàåì êóðñîð
    w.hIcon=0; //èêîíêè ó íàñ íå áóäåò ïîêà
    w.lpszMenuName=0; //è ìåíþ ïîêà íå áóäåò
    w.hbrBackground = LTGRAY_BRUSH; //WHITE_BRUSH;// öâåò ôîíà îêíà
    w.style=CS_HREDRAW|CS_VREDRAW; //ñòèëü - ïåðåðèñîâûâàåìîå ïî õ è ïî ó
    w.cbClsExtra=0;
    w.cbWndExtra=0;

    if(!RegisterClass(&w))
        return 0;

   // HWND hWnd;
    //MSG lpMsg;

//Ñîçäàäèì îêíî â ïàìÿòè, çàïîëíèâ àðãóìåíòû CreateWindow
    hWnd=CreateWindow(ProgName, //Èìÿ ïðîãðàììû
        "Ëàáîðàòîðíà ðîáîòà 3. Âèêîíàëà Ñàí³íà À. Ì.", //Çàãîëîâîê îêíà
        WS_OVERLAPPEDWINDOW, //Ñòèëü îêíà - ïåðåêðûâàþùååñÿ
        400, //ïîëîæåíèå îêíà íà ýêðàíå ïî õ
        100, //ïîëîæåíèå ïî ó
        960, //øèðèíà
        600, //âèñîòà
        (HWND)NULL, //èäåíòèôèêàòîð ðîäèòåëüñêîãî îêíà
        (HMENU)NULL, //èäåíòèôèêàòîð ìåíþ
        (HINSTANCE)hInstance, //èäåíòèôèêàòîð ýêçåìïëÿðà ïðîãðàììû
        (HINSTANCE)NULL); //îòñóòñòâèå äîïîëíèòåëüíûõ ïàðàìåòðîâ

//Âûâîäèì îêíî èç ïàìÿòè íà ýêðàí
    ShowWindow(hWnd, nCmdShow);
//Îáíîâèì ñîäåðæèìîå îêíà
 //   UpdateWindow(hWnd);

//Öèêë îäåðæàííÿ ïîâ³äîìëåíü

    while(GetMessage(&lpMsg, hWnd, 0, 0)) {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
    return(lpMsg.wParam);
    }

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
                        WPARAM wParam, LPARAM lParam)
    {
    HDC hdc;
    PAINTSTRUCT ps;

    void arrow(float fi, int px,int py){

            int lx,ly,rx,ry;
            lx = px+15*cos(fi+0.3);
            rx = px+15*cos(fi-0.3);
            ly = py+15*sin(fi+0.3);
            ry = py+15*sin(fi-0.3);
            MoveToEx(hdc, lx, ly, NULL);
            LineTo(hdc, px, py);
            LineTo(hdc, rx, ry);

      }
    double** symmetricalMatrix(double **matrix, int r, int c){
             for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                       if (matrix[i][j] == 1) matrix[j][i] = 1;
                }
            }
        return matrix;

        }

    switch(messg){
        case WM_PAINT :

            hdc=BeginPaint(hWnd, &ps);

            int n=12;
            char *nn[20] = {"1","2","3","4","5","6","7","8","9","10",
                       "11","12","13","14","15","16","17","18","19","20"};
            int nx[12] = {};
            int ny[12] = {};
            int dx = 16, dy = 16, dtx = 5;
            int i, j;
            int radius = 200;
            int centreX = 400;
            int centreY = 300;
            for (int i = 0; i < n; i++){
                nx[i] = centreX + radius * cos(2*PI*i/(n));
                ny[i] = centreY + radius * sin(2*PI*i/(n));
            }

            HPEN BPen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
            HPEN KPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));

        srand(0421);
        double** T = randm(n, n);
        double coef = 1 - 2*0.02 - 1*0.005 - 0.25;
        double** A = mulmr(coef, T, n, n);
             for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%g ", A[i][j]);
            }
            printf("\n");
        }
        symmetricalMatrix(A, n, n);
        printf("\nSymmetrical matrix\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%g ", A[i][j]);
            }
            printf("\n");
        }
int nx0, ny0, Radius;
SelectObject(hdc, KPen);
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (A[i][j] == 1){
                            if (i == j){
                                    if(i <= (n-1)/4){
                                Arc(hdc, nx[j], ny[j], nx[j]+40, ny[j]+40,    nx[j], ny[j], nx[j], ny[j]);
                                }
                                    else if(i > (n-1)/4 && i <= (n-1)/2  ){
                                        Arc(hdc, nx[j], ny[j], nx[j]-40, ny[j]+40,    nx[j], ny[j], nx[j], ny[j]);
                                    }
                                    else if(i > (n-1)/2 && i <= (3*(n-1))/4 ){
                                        Arc(hdc, nx[j], ny[j], nx[j]-40, ny[j]-40,    nx[j], ny[j], nx[j], ny[j]);
                                    }
                                     else {
                                        Arc(hdc, nx[j], ny[j], nx[j]+40, ny[j]-40,    nx[j], ny[j], nx[j], ny[j]);
                                    }
                                continue;
                           } else if  ((A[j][i]==1) && (i>j)) {
                                nx0=((nx[i]+nx[j])/2)-((ny[i]-ny[j]));
                                ny0=((ny[i]+ny[j])/2)+((nx[i]-nx[j]));
                                Radius=(sqrt(pow(nx[j]-nx0, 2)+pow(ny[j]-ny0, 2)));
                                Arc(hdc, nx0-Radius, ny0-Radius, nx0+Radius, ny0+Radius, nx[i], ny[i], nx[j], ny[j]);
                                continue;
                            }
                        MoveToEx(hdc, nx[i], ny[i], NULL);
                        LineTo(hdc, nx[j], ny[j]);
                    }
                }
            }

        SelectObject(hdc, BPen);
           for(i=0;i < n;i++){
              Ellipse(hdc, nx[i]-dx,ny[i]-dy,nx[i]+dx,ny[i]+dy);
              TextOut(hdc, nx[i]-dtx,ny[i]-dy/2,  nn[i], 2);
            }

            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return 0;
}

