#if !defined(PY_SSIZE_T_CLEAN)
#define PY_SSIZE_T_CLEAN

#include </usr/include/python3.6/Python.h>

class PythonCode
{
private:
    wchar_t *program;
    int maxLines = 100;
public:
    PythonCode(char *argv[]);

    int getMaxLines();

    void executePython(const char* code[]);

    ~PythonCode();
};

#endif // PY_SSIZE_T_CLEAN
