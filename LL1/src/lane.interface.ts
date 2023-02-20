export type Sym = 'a' | 'b' | '3' | '8' | '+' | '*' | '-' | '(' | ')' | '\n';

export function isOfSym(value: string): value is Sym {
	return ['a', 'b', '3', '8', '+', '*', '-', '(', ')', '\n'].includes(value);
}

export interface Lane {
	name: string;
	symbols: string[];
	shift: boolean;
	error: boolean;
	ref: number;
	onStack: boolean;
	end: boolean;
}
