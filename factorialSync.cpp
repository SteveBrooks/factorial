#include "factorialSync.h"

using v8::String;
using v8::Number;

NAN_METHOD(FactorialSync)
{
    NanScope();

    if(!args[0]->IsNumber())
    {
        return ThrowException(NanNew<String>("The argument must be a number."));
    }

    // expect a number as the first argument
    int n = args[0]->Int32Value();

    if( n <= 0 )
    {
        return ThrowException(NanNew<String>("Only positive factorials are allowed."));
    }

    double factorial = 1;
    for(double i=1; i<=n; i++)
    {
        factorial *= i;
    }

    NanReturnValue(NanNew<Number>(factorial));
}

NAN_METHOD(FactorialSync);

