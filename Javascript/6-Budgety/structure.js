var budgetController = (function() {
    var x = 23;
    
    var add = function(a) {
        return x + a;
    }
    // x와 add는 closure 안에 있고 외부에서는 접근 불가능 (private)
    return {
        publicTest: function(b) {
            // console.log(add(b));
            return add(b);
        }
    }
    // publicTest는 closure 원리로 인해 x와 add에 접근 가능.
    // 외부에서도 접근 가능 (public)
})();

var UIController = (function() {
    // Some code
})();

var controller = (function(budgetCtrl, UICtrl) {
    var z = budgetCtrl.publicTest(5);
    
    return {
        anotherPublic: function() {
            console.log(z);
        }
    }
})(budgetController, UIController);