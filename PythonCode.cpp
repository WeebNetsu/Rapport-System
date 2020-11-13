// g++ -I/usr/include/python3.6/ main.cpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -o output

#include "PythonCode.hpp"

PythonCode::PythonCode(char *argv[]){
    this->program = Py_DecodeLocale(argv[0], NULL);

    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    Py_SetProgramName(program);  /* optional but recommended */
    Py_Initialize();
}

int PythonCode::getMaxLines(){
    return this->maxLines;
}

void PythonCode::executePython(const char* code[]){
    for (int i = 0; i < getMaxLines(); i++){
        if (code[i] != nullptr){
           PyRun_SimpleString(code[i]);
        }
    }
    
}

PythonCode::~PythonCode(){
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
}