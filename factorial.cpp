#include <node.h>
#include <nan.h>

#include "factorialSync.h"
#include "factorialAsync.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using v8::Number;

void InitAll(Handle<Object> exports)
{
    exports->Set(NanNew<String>("factorialSync"),
        NanNew<FunctionTemplate>(FactorialSync)->GetFunction());

    exports->Set(NanNew<String>("factorialAsync"),
        NanNew<FunctionTemplate>(FactorialAsync)->GetFunction());
}

NODE_MODULE(factorial, InitAll)
