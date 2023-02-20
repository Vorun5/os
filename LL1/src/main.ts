import { ll1 } from './ll1';

/*
Valid tests:
	1. --b 
	2. a+b
	3. -(a+b)
	4. (-8)
	5. b+-a
	6. a+(-3)
	7. -(8*b*-((b*-3)*-8+(-3)))
	8. (a+-b*(-a+3)+((a+b)+((a*-b)))+((((a+8)+(a*8)))))
	
Invalid tests:
	1. empty
	2. )
	3. (
	4. (3
	5. a)
	6. +a*b
	7. 3**a		
	8. *-8+b
	9. a3
*/

const validTest: string[] = [
	'--b',
	'a+b',
	'a*b',
	'-(a+b)',
	'(-8)',
	'b+-a',
	'a+(-3)',
	'-(8*b*-((b*-3)*-8+(-3)))',
	'(a+-b*(-a+3)+((a+b)+((a*-b)))+((((a+8)+(a*8)))))',
];

const invalidTest: string[] = [
	'empty',
	')',
	'(',
	'(3',
	'a)',
	'+a*b',
	'+a*b',
	'3**a	',
	'*-8+b',
	'a3',
];

console.log('\n\n\nVALID TESTS');
for (let i = 0; i < validTest.length; i++) {
	const test = validTest[i];
	const result = ll1(test);
	console.log(`${i + 1}. ${test}\t\t${result ? 'successful' : 'crash'}`);
}

console.log('\n\n\nINVALID TESTS');
for (let i = 0; i < invalidTest.length; i++) {
	const test = invalidTest[i];
	const result = ll1(test);
	console.log(`${i + 1}. ${test}\t\t${!result ? 'successful' : 'crash'}`);
}

// const text = 'a+b';
// const result = ll1(text);
// console.log(result ? 'valid' : 'invalid');

// ✅ read file ASYNCHRONOUSLY
/*
async function asyncReadFile(filename: string) {
	try {
		const contents = await promises.readFile(filename, 'utf-8');

		const arr = contents.split(",");

		console.log(arr); // 👉️ ['One', 'Two', 'Three', 'Four']

		return arr;
	} catch (err) {
		console.log(err);
	}
}

asyncReadFile('./files/example.txt');
*/
export {};
