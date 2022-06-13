let Expression = null

Module = {
    onRuntimeInitialized: () => {
        Expression = Module.Expression
    }
}

function changeInput(input) {
    let valueDom = document.getElementById('expr-value')

    let expr = new Expression(input)
    try {
        let value = expr.evaluate()
        valueDom.innerText = value
    } catch(_) {
        valueDom.innerText = "Invalid expression"
    }
}
