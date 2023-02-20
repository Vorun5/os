"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.ll1 = void 0;
const table_1 = __importDefault(require("./table"));
function ll1(text, log = false) {
    const stack = [];
    let index = 0;
    let chIndex = 0;
    let count = 0;
    while (true) {
        count++;
        const lane = table_1.default[index];
        const sym = chIndex >= text.length ? '\n' : text[chIndex];
        const found = lane.symbols.includes(sym);
        if (log)
            console.log(`${count}\t${sym === '\n' ? 'end' : sym} \t ${found}-${index
                .toString()
                .padStart(3, '0')}\t[${stack.length === 0 ? 'stack is empty' : stack.join(', ')}]\n`);
        if (!found) {
            if (lane.error) {
                if (log)
                    console.log('Expected: ', lane.symbols, '; Found: ', sym);
                return false;
            }
            index++;
            continue;
        }
        if (lane.shift)
            chIndex++;
        if (lane.onStack)
            stack.push(index + 1);
        if (lane.ref !== -1)
            index = lane.ref;
        else {
            if (stack.length === 0 && lane.end)
                return true;
            if (stack.length === 0) {
                if (log)
                    console.log('Stack is empty!');
                return false;
            }
            else
                index = stack.pop();
        }
    }
}
exports.ll1 = ll1;
//# sourceMappingURL=ll1.js.map