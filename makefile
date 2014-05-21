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
