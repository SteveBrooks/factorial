var should = require('chai').should();
var factorial = require('../build/Release/factorial.node');

describe('factorial', function() {

    it('should not be undefined', function() {
        factorial.should.be.ok;
        factorial.should.be.a('object');
    })

    describe('factorialSync', function() {

        it('should return 1 for 1!', function() {
            var result = factorial.factorialSync(1);
            result.should.be.ok;
            result.should.be.a('number');
            result.should.be.equal(1);
        });

        it('should return 2 for 2!', function() {
            var result = factorial.factorialSync(2);
            result.should.be.ok;
            result.should.be.a('number');
            result.should.be.equal(2);
        });

        it('should return 6 for 3!', function() {
            var result = factorial.factorialSync(3);
            result.should.be.ok;
            result.should.be.a('number');
            result.should.be.equal(6);
        });

        it('should return greater than 9.33E+157 for 100!', function() {
            var result = factorial.factorialSync(100);
            result.should.be.ok;
            result.should.be.a('number');
            result.should.be.least(9.33E+157);
        });

        it('should throw for negative numbers', function() {
            (function() {
                factorial.factorialSync(-1)
            }).should.throw('Only positive factorials are allowed.');
        });

        it('should throw for zero', function() {
            (function() {
                factorial.factorialSync(0)
            }).should.throw('Only positive factorials are allowed.');
        });

        it('should throw for non-numeric', function() {
            (function() {
                factorial.factorialSync('X')
            }).should.throw('The argument must be a number.');
        });
    });

});
