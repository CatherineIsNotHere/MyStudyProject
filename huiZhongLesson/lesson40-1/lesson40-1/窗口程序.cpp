#include <windows.h>
//#include <tchar.h>
const wchar_t g_szClassName[] = __TEXT("mywindowsclass");
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,msg,wparam,lparam);
	}
	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdshow)
{
	MessageBox(NULL, __TEXT("HELLO WIN32"), __TEXT("windows program"), MB_OK);
	//1ע�ᴰ����
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);//�ṹ���С
	wc.style = 0;//��ķ��ͨ��Ϊ0����
	wc.lpfnWndProc = WndProc;//��Ϣ����ص�����
	wc.cbWndExtra = 0;//�ڴ���Ϊ������ڶ�������������С��ͨ��Ϊ0
	wc.cbClsExtra = 0;//�ڴ���Ϊ��������Ķ������������С��ͨ����0
	wc.hInstance = hInstance;//ʵ�����
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);//ͼ��
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);//���
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//����ɫ
	wc.lpszMenuName = NULL;//�˵�
	wc.lpszClassName = g_szClassName;//����
	wc.hIconSm = LoadIcon(NULL,IDI_APPLICATION);//Сͼ��
	if (!RegisterClassEx(&wc)){//���򴰿���
		MessageBox(NULL,__TEXT("����ע��ʧ�ܣ�"),__TEXT("error"),MB_OK);
		return 0;
	}
	//2��������
	HWND hwnd=CreateWindowEx(
			WS_EX_CLIENTEDGE,//��չ�Ĵ��ڷ��
			g_szClassName,//��������
			__TEXT("this is title"),//���ڱ���
			WS_OVERLAPPEDWINDOW,//���ڵ���ʽ����
			CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,//xywh
			NULL, NULL, hInstance, NULL);//���ڵĸ����ھ�������ڲ˵������ʵ����������ڴ����ĸ��Ӳ���
	if (hwnd==NULL){
		MessageBox(NULL,__TEXT("���ڴ���ʧ��"),__TEXT("error"),MB_OK);
		return 0;
	}
	//3��ʾ����
	ShowWindow(hwnd,nCmdshow);
	UpdateWindow(hwnd);
	//4��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//UnregisterClass();

	return 0;
}
