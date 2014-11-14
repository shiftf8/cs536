{"changed":true,"filter":false,"title":"h7.doublelinkedlist.cpp","tooltip":"/h7.doublelinkedlist.cpp","value":"//Lamog, Robert\n//Homework #7\n//Hart\n//11/6/14\n\n#include <cstdlib>\n#include <iostream>\n#include <string>\nusing namespace std;\n\nclass List2{\npublic:\n    List2();\n    void addFront( const string & item );\n    void addBack( const string & item );\n    string removeFront();\n    string removeBack();\n    bool empty() const;\n    unsigned size() const;\n    void show() const;\nprivate:\n    unsigned LIST_SIZE;\n    struct Node{\n        string data;\n            // If this node is the last node in the list, next is NULL.\n            // Otherwise, next points to the next Node in the list.\n        Node * next;\n            // If this node is the first node in the list, prev is NULL.\n            // Otherwise, prev points to the previous Node in the list.\n        Node * prev;\n    };\n        // If the list is empty, front is NULL.\n        // Otherwise, front points to the first Node in the list\n    Node * front;\n        // If the list is empty, back is NULL.\n        // Otherwise, back points to the last node in the list\n    Node * back;\n}; // class List2\n\nbool die( const string & msg );\n\nint main() {\n    \n    return 0;\n}\n\nList2::List2: front(NULL), back(NULL), LIST_SIZE(0) {}\nvoid List2::addFront( const string & item ) {\n    \n}\n\nbool die( const string & msg ) {\n    cerr <<endl <<\"Fatal error: \" <<msg <<endl;\n    exit( EXIT_FAILURE );\n    \n    // cout <<endl <<\"Fatal error: \" <<msg <<endl;\n    // return true;\n}","undoManager":{"mark":-56,"position":100,"stack":[[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":45,"column":51},"end":{"row":45,"column":52}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":45,"column":52},"end":{"row":45,"column":53}},"text":"{"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":45,"column":53},"end":{"row":45,"column":54}},"text":"}"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":20,"column":8},"end":{"row":21,"column":0}},"text":"\n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":0},"end":{"row":21,"column":1}},"text":"L"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":21,"column":0},"end":{"row":21,"column":1}},"text":"L"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":0},"end":{"row":21,"column":1}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":1},"end":{"row":21,"column":2}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":2},"end":{"row":21,"column":3}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":3},"end":{"row":21,"column":4}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":4},"end":{"row":21,"column":5}},"text":"u"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":5},"end":{"row":21,"column":6}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":21,"column":4},"end":{"row":21,"column":6}},"text":"un"},{"action":"insertText","range":{"start":{"row":21,"column":4},"end":{"row":21,"column":12}},"text":"unsigned"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":12},"end":{"row":21,"column":13}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":13},"end":{"row":21,"column":14}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":14},"end":{"row":21,"column":15}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":15},"end":{"row":21,"column":16}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":21,"column":15},"end":{"row":21,"column":16}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":21,"column":14},"end":{"row":21,"column":15}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":21,"column":13},"end":{"row":21,"column":14}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":13},"end":{"row":21,"column":14}},"text":"L"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":21,"column":13},"end":{"row":21,"column":14}},"text":"L"},{"action":"insertText","range":{"start":{"row":21,"column":13},"end":{"row":21,"column":22}},"text":"LIST_SIZE"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":21,"column":22},"end":{"row":21,"column":23}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":46,"column":54},"end":{"row":47,"column":0}},"text":"\n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":0},"end":{"row":47,"column":1}},"text":"L"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":47,"column":0},"end":{"row":47,"column":1}},"text":"L"},{"action":"insertText","range":{"start":{"row":47,"column":0},"end":{"row":47,"column":5}},"text":"List2"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":5},"end":{"row":47,"column":6}},"text":":"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":6},"end":{"row":47,"column":7}},"text":":"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":7},"end":{"row":47,"column":38}},"text":"addFront( const string & item )"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":38},"end":{"row":47,"column":39}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":39},"end":{"row":47,"column":40}},"text":"{"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":40},"end":{"row":48,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":48,"column":0},"end":{"row":49,"column":0}},"lines":["    "]},{"action":"insertText","range":{"start":{"row":49,"column":0},"end":{"row":49,"column":1}},"text":"}"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":0},"end":{"row":47,"column":1}},"text":"v"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":1},"end":{"row":47,"column":2}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":2},"end":{"row":47,"column":3}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":3},"end":{"row":47,"column":4}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":47,"column":4},"end":{"row":47,"column":5}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":53,"column":25},"end":{"row":54,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":54,"column":0},"end":{"row":54,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":54,"column":4},"end":{"row":55,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":55,"column":0},"end":{"row":55,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":4},"end":{"row":55,"column":5}},"text":"c"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":5},"end":{"row":55,"column":6}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":6},"end":{"row":55,"column":7}},"text":"u"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":7},"end":{"row":55,"column":8}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":8},"end":{"row":55,"column":9}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":9},"end":{"row":55,"column":10}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":10},"end":{"row":55,"column":11}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":11},"end":{"row":55,"column":12}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":12},"end":{"row":55,"column":13}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":13},"end":{"row":55,"column":14}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":14},"end":{"row":55,"column":15}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":15},"end":{"row":55,"column":16}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":16},"end":{"row":55,"column":17}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":17},"end":{"row":55,"column":18}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":18},"end":{"row":55,"column":20}},"text":"\"\""}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":19},"end":{"row":55,"column":20}},"text":"F"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":20},"end":{"row":55,"column":21}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":21},"end":{"row":55,"column":22}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":22},"end":{"row":55,"column":23}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":23},"end":{"row":55,"column":24}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":24},"end":{"row":55,"column":25}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":25},"end":{"row":55,"column":26}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":26},"end":{"row":55,"column":27}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":27},"end":{"row":55,"column":28}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":28},"end":{"row":55,"column":29}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":29},"end":{"row":55,"column":30}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":30},"end":{"row":55,"column":31}},"text":":"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":31},"end":{"row":55,"column":32}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":33},"end":{"row":55,"column":34}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":34},"end":{"row":55,"column":35}},"text":","}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":55,"column":34},"end":{"row":55,"column":35}},"text":","}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":34},"end":{"row":55,"column":35}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":35},"end":{"row":55,"column":36}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":36},"end":{"row":55,"column":37}},"text":"m"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":37},"end":{"row":55,"column":38}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":38},"end":{"row":55,"column":39}},"text":"g"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":39},"end":{"row":55,"column":40}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":40},"end":{"row":55,"column":41}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":41},"end":{"row":55,"column":42}},"text":"<"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":42},"end":{"row":55,"column":43}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":43},"end":{"row":55,"column":44}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":44},"end":{"row":55,"column":45}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":45},"end":{"row":55,"column":46}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":46},"end":{"row":55,"column":47}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":55,"column":46},"end":{"row":55,"column":47}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":46},"end":{"row":55,"column":47}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":47},"end":{"row":56,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":56,"column":0},"end":{"row":56,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":4},"end":{"row":56,"column":5}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":5},"end":{"row":56,"column":6}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":6},"end":{"row":56,"column":7}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":7},"end":{"row":56,"column":8}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":56,"column":7},"end":{"row":56,"column":8}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":7},"end":{"row":56,"column":8}},"text":"u"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":8},"end":{"row":56,"column":9}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":9},"end":{"row":56,"column":10}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":10},"end":{"row":56,"column":11}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":11},"end":{"row":56,"column":12}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":12},"end":{"row":56,"column":13}},"text":"r"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":13},"end":{"row":56,"column":14}},"text":"u"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":14},"end":{"row":56,"column":15}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":56,"column":15},"end":{"row":56,"column":16}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":55,"column":4},"end":{"row":55,"column":7}},"text":"// "},{"action":"insertText","range":{"start":{"row":56,"column":4},"end":{"row":56,"column":7}},"text":"// "}]}]]},"ace":{"folds":[],"scrolltop":507.5,"scrollleft":0,"selection":{"start":{"row":48,"column":4},"end":{"row":48,"column":4},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":147,"mode":"ace/mode/c_cpp"}},"timestamp":1415942795850}