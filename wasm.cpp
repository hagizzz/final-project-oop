
// cmd: emcc -lembind -o public/scripts/expression.js wasm.cpp

#include <emscripten/bind.h>

#include "lib.h"
#include "include.h"

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS(expression) {
    class_<Expression>("Expression")
    .constructor<string>()
    .function("evaluate", &Expression::evaluate);
}
