#ifdef MYDLL_EXPORTS
#define MYDLL_API _declspec(dllexport)
#else
#define MYDLL_API _declspec(dllimport)

#endif // MYDLL_EXPORTS


namespace hhh{
	int MYDLL_API myadd(int a, int b);
}

