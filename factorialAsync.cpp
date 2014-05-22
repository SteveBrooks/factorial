#include "factorialAsync.h"

using v8::Function;
using v8::Local;
using v8::Null;
using v8::Number;
using v8::Value;
using v8::String;
using v8::Handle;

class FactorialWorker : public NanAsyncWorker
{
public:
    FactorialWorker(NanCallback* callback, int n) : NanAsyncWorker(callback), n(n) { }

    virtual ~FactorialWorker() { }

    void Execute()
    {
        factorial = 1;
        for(double i=1; i<=n; i++)
        {
            factorial *= i;
        }
    }

    void HandleOKCallback()
    {
        NanScope();

        Handle<Value> argv[] = {
            NanNull(), // Null Error
            NanNew<Number>(factorial)
        };

        callback->Call(2, argv);
    }

private:
    int     n;
    double  factorial;
};


NAN_METHOD(FactorialAsync)
{
    NanScope();

    if(!args[0]->IsNumber())
    {
        return ThrowException(NanNew<String>("The first argument must be a number."));
    }

    // expect a number as the first argument
    int n = args[0]->Int32Value();

    if( n <= 0 )
    {
        return ThrowException(NanNew<String>("Only positive factorials are allowed."));
    }

    if(!args[1]->IsFunction())
    {
        return ThrowException(NanNew<String>("The second argument must be a function."));
    }

    NanCallback* callback = new NanCallback(args[1].As<Function>());

    NanAsyncQueueWorker(new FactorialWorker(callback, n));

    NanReturnUndefined();
}
