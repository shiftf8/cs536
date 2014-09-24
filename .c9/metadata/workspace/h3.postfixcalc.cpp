{"changed":true,"filter":false,"title":"h3.postfixcalc.cpp","tooltip":"/h3.postfixcalc.cpp","value":"//Lamog, Robert\n//Homework #3\n//Hart\n//09/29/14\n\n#include <iostream>\n#include <sstream>\nusing namespace std;\n\n#define STACK_SIZE 8\n\nclass Stack{\npublic:\n\tStack(); // ctor corresponds to last week's initialize function\n\tdouble pop(); // c&d (complain and die) on underflow\n\tdouble top() const; // c&d on underflow\n\tStack & push( double item ); // return reference to self (*this)\n\tunsigned elements() const; // returns some # in the range [0, STACK_SIZE]\nprivate:\n\t// data corresponds to last week's assignment, but now it's private\n\tdouble myData[ STACK_SIZE ];\n\tunsigned myElements;\n}; // class Stack\n\nbool calculate( double & result, const string & expression );\n\nbool die( const string & msg );\n\nint main() {\n    double result = 0.0;\n    string expression = \"1.1 2.2 +\";\n    \n    calculate(result, expression);\n    \n    return 0;\n} //main()\n\nStack::Stack(){\n    myData[ STACK_SIZE ];\n    myElements = 0;\n}\ndouble Stack::pop(){\n    if (myElements == 0) die(\"stack underflow.\");\n    return myData[--myElements];\n}\ndouble Stack::top() const {\n    if (myElements == 0) die(\"stack underflow.\");\n    return myData[myElements - 1];\n}\nStack & Stack::push( double item ) {\n    if (myElements == STACK_SIZE) die(\"stack overflow.\");\n    myData[myElements++] = item;\n}\nunsigned Stack::elements() const {\n    return myElements;\n}\n\nbool calculate( double & result, const string & expression ){\n    Stack st;\n    istringstream sin(expression);\n    \n    for (string token; sin >> token;) {\n        parse(token);\n    }\n    \n    return false;\n}\ndouble parse( const string & token ) {\n    double val = 0.0;\n    string operand;\n    \n    \n} \n\nbool die( const string & msg ) {\n\t//cerr <<endl <<\"Fatal error: \" <<msg << endl;\n\t//exit( EXIT_FAILURE );\n\n\tcout << endl << \"Fatal error: \" << msg << endl;\n\treturn true;\n}","undoManager":{"mark":-3,"position":100,"stack":[[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":10},"end":{"row":62,"column":11}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":11},"end":{"row":62,"column":12}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":12},"end":{"row":62,"column":13}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":13},"end":{"row":62,"column":15}},"text":"()"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":14},"end":{"row":62,"column":15}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":15},"end":{"row":62,"column":16}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":16},"end":{"row":62,"column":17}},"text":"k"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":17},"end":{"row":62,"column":18}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":18},"end":{"row":62,"column":19}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":62,"column":20},"end":{"row":62,"column":21}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":66,"column":1},"end":{"row":67,"column":0}},"text":"\n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":0},"end":{"row":67,"column":1}},"text":"b"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":0},"end":{"row":67,"column":1}},"text":"b"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":0},"end":{"row":67,"column":1}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":1},"end":{"row":67,"column":2}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":2},"end":{"row":67,"column":3}},"text":"u"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":3},"end":{"row":67,"column":4}},"text":"b"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":4},"end":{"row":67,"column":5}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":5},"end":{"row":67,"column":6}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":6},"end":{"row":67,"column":7}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":7},"end":{"row":67,"column":8}},"text":"p"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":8},"end":{"row":67,"column":9}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":9},"end":{"row":67,"column":10}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":10},"end":{"row":67,"column":11}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":11},"end":{"row":67,"column":12}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":12},"end":{"row":67,"column":13}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":12},"end":{"row":67,"column":13}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":12},"end":{"row":67,"column":14}},"text":"()"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":13},"end":{"row":67,"column":14}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":14},"end":{"row":67,"column":15}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":15},"end":{"row":67,"column":16}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":16},"end":{"row":67,"column":17}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":17},"end":{"row":67,"column":18}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":18},"end":{"row":67,"column":19}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":19},"end":{"row":67,"column":20}},"text":"g"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":19},"end":{"row":67,"column":20}},"text":"g"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":18},"end":{"row":67,"column":19}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":17},"end":{"row":67,"column":18}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":16},"end":{"row":67,"column":17}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":15},"end":{"row":67,"column":16}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":67,"column":14},"end":{"row":67,"column":15}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":14},"end":{"row":67,"column":15}},"text":"c"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":15},"end":{"row":67,"column":16}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":16},"end":{"row":67,"column":17}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":17},"end":{"row":67,"column":18}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":18},"end":{"row":67,"column":19}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":19},"end":{"row":67,"column":20}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":20},"end":{"row":67,"column":21}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":21},"end":{"row":67,"column":22}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":22},"end":{"row":67,"column":23}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":23},"end":{"row":67,"column":24}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":24},"end":{"row":67,"column":25}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":25},"end":{"row":67,"column":26}},"text":"g"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":26},"end":{"row":67,"column":27}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":27},"end":{"row":67,"column":28}},"text":"&"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":28},"end":{"row":67,"column":29}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":29},"end":{"row":67,"column":30}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":30},"end":{"row":67,"column":31}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":31},"end":{"row":67,"column":32}},"text":"k"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":32},"end":{"row":67,"column":33}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":33},"end":{"row":67,"column":34}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":35},"end":{"row":67,"column":36}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":34},"end":{"row":67,"column":35}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":36},"end":{"row":67,"column":37}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":37},"end":{"row":67,"column":38}},"text":"{"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":67,"column":38},"end":{"row":68,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":68,"column":0},"end":{"row":69,"column":0}},"lines":["    "]},{"action":"insertText","range":{"start":{"row":69,"column":0},"end":{"row":69,"column":1}},"text":"}"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":4},"end":{"row":68,"column":5}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":5},"end":{"row":68,"column":6}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":6},"end":{"row":68,"column":7}},"text":"u"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":7},"end":{"row":68,"column":8}},"text":"b"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":8},"end":{"row":68,"column":9}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":9},"end":{"row":68,"column":10}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":10},"end":{"row":68,"column":11}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":11},"end":{"row":68,"column":12}},"text":"v"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":12},"end":{"row":68,"column":13}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":13},"end":{"row":68,"column":14}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":14},"end":{"row":68,"column":15}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":15},"end":{"row":68,"column":16}},"text":"="}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":16},"end":{"row":68,"column":17}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":17},"end":{"row":68,"column":18}},"text":"0"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":18},"end":{"row":68,"column":19}},"text":"."}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":19},"end":{"row":68,"column":20}},"text":"0"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":20},"end":{"row":68,"column":21}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":68,"column":21},"end":{"row":69,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":69,"column":0},"end":{"row":69,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":4},"end":{"row":69,"column":5}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":5},"end":{"row":69,"column":6}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":6},"end":{"row":69,"column":7}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":7},"end":{"row":69,"column":8}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":8},"end":{"row":69,"column":9}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":9},"end":{"row":69,"column":10}},"text":"g"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":10},"end":{"row":69,"column":11}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":11},"end":{"row":69,"column":12}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":12},"end":{"row":69,"column":13}},"text":"p"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":13},"end":{"row":69,"column":14}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":14},"end":{"row":69,"column":15}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":15},"end":{"row":69,"column":16}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":16},"end":{"row":69,"column":17}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":17},"end":{"row":69,"column":18}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":18},"end":{"row":69,"column":19}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":19},"end":{"row":70,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":70,"column":0},"end":{"row":70,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":4},"end":{"row":71,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":71,"column":0},"end":{"row":71,"column":4}},"text":"    "}]}]]},"ace":{"folds":[],"scrolltop":729,"scrollleft":0,"selection":{"start":{"row":71,"column":4},"end":{"row":71,"column":4},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":47,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1411519638929}