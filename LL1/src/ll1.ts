import { Lane } from './lane.interface';

export type LL1Table = Lane[];

export function ll1(
	text: string,
	table: LL1Table,
	log: boolean = false
): boolean {
	const stack: number[] = [];
	let index: number = 0;
	let chIndex: number = 0;

	let count = 0;
	while (true) {
		count++;

		const lane = table[index];
		const sym = chIndex >= text.length ? '\n' : text[chIndex];
		//console.log(`-- ${index} ${sym} --`);
		const found = lane.symbols.includes(sym);

		if (log)
			console.log(
				`${count}:\tsym: ${sym === '\n' ? 'END' : sym}\t name: ${
					lane.name
				}\t${found}-${index.toString().padStart(3, '0')}\t next: ${
					lane.ref
				}\tsymbs: [${lane.symbols.join(', ')}] \t error: ${
					lane.error
				}\t NOS: ${lane.onStack}\tshift: ${lane.shift}\t \t [${
					stack.length === 0 ? 'stack is empty' : stack.join(', ')
				}] i = ${chIndex}\tend: ${lane.end}\n`
			);
		// console.log(
		// 	`${count}\t${sym === '\n' ? 'END' : sym} \t ${found}-${index
		// 		.toString()
		// 		.padStart(3, '0')}\t[${
		// 		stack.length === 0 ? 'stack is empty' : stack.join(', ')
		// 	}]\n`
		// );
		if (!found && lane.name == 'n') {
			index = stack.pop()!;
			//if (stack.length == 0 && lane.name == 'n') {
			//	return false;
			//}
			if (index == undefined) {
				return false;
			}
			continue;
		}
		if (!found) {
			if (lane.error) {
				if (log)
					console.log('Expected: ', lane.symbols, '; Found: ', sym);
				return false;
			}
			index++;
			continue;
		}

		if (lane.shift) chIndex++;

		if (lane.onStack) stack.push(index + 1);

		if (lane.ref !== -1) index = lane.ref;
		else {
			if (stack.length === 0 && lane.end) return true;

			if (stack.length === 0) {
				if (log) console.log('Stack is empty!');
				return false;
			} else {
				index = stack.pop()!;
				if (index == undefined) {
					return false;
				}
				//if (stack.length == 0 && lane.name == 'n') {
				//		return false;
				//}
			}
		}
	}
}
