Steps for creating a native add-in for NodeJS
=============================================

1. Install node-gyp locally

    $ npm install node-gyp

2. Create directory for module

    $ md hello

3.  Add native module

    $ ed hello.cpp

        #include <node.h>
        #include <v8.h>

        using namespace v8;

        Handle<Value> Method(const Arguments& args) {
          HandleScope scope;
          return scope.Close(String::New("world"));
        }

        void init(Handle<Object> target) {
          target->Set(String::NewSymbol("hello"),
              FunctionTemplate::New(Method)->GetFunction());
        }
        NODE_MODULE(hello, init)

4. Add binding.gyp for module

    $ ed binding.gyp

        {
          "targets": [
            {
              "target_name": "hello",
              "sources": [ "hello.cpp" ]
            }
          ]
        }

5. Configure and build the project

    $ ./node_modules/.bin/node-gyp configure build

6. Create test directory

    $ md test

7. Install mocha test framework locally

    $ npm install mocha

8. Add a mocha.opts file to the test directory

    $ ed ./test/mocha.opts

        test/**/*.test.js --reporter dot --ui bdd --growl

9. Install chai locally

    $ npm install chai

10. Add a test for the module to the test directory.

    $ ed ./test/hello.js

        var should = require('chai').should();
        var helloaddon = require('../build/Release/hello.node');

        describe('hello', function() {
            it('should return \'world\'', function(){
                helloaddon.hello().should.equal('world');
            });
        });

11. Run the test

    $ ./node_modules/.bin/mocha

12. Add a package.json file to install the dependencies

    $ ed package.json

        {
          "name": "hello"
          , "description": "Native addon example"
          , "keywords": ["hello world"]
          , "author": "stevebrooks"
          , "dependencies": {
                "chai": "1.9.1"
                , "mocha": "1.19.0"
                , "node-gyp": "0.13.1"
            }
          , "lib"           : "."
        }

13. Be nice, add a makefile

    $ ed makefile

        all: npm build test

        clean:
            rm -rdf ./build
            rm -rdf ./node_modules

        npm:
            npm install

        build:
            @NODE_ENV=build ./node_modules/.bin/node-gyp configure build

        test:
            @NODE_ENV=test ./node_modules/.bin/mocha

        test-w:
            @NODE_ENV=test ./node_modules/.bin/mocha --watch

        .PHONY: test test-w
