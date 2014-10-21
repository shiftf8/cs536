{"changed":true,"filter":false,"title":"h6.singleylinkedlist.cpp","tooltip":"/h6.singleylinkedlist.cpp","value":"//Lamog, Robert\n//Homework #6\n//Hart\n//10/20/14\n\n#include <iostream>\n#include <string>\nusing namespace std;\n\nclass List1 {\npublic:\n    List1();\n    void addFront( const string & item );\n    void addBack( const string & item );\n    string removeFront();\n    string removeBack();\n    bool empty() const;\n    unsigned size() const;\n    void show() const;\nprivate:\n    struct Node{\n        string data;\n        Node * next;\n    };\n    Node * head;\n}; // class List1\n\nbool die( const string & msg );\n\nint main() {\n    List1 aList;\n    \n    aList.addFront(\"michael\");\n    aList.addFront(\"george\");\n    aList.addFront(\"henry\");\n    // aList.show();\n    // cout <<aList.size() <<endl;\n    // cout <<endl;\n    // aList.addBack(\"xavier\");\n    // aList.show();\n    // cout <<aList.size() <<endl;\n    // cout <<endl;\n    // aList.addBack(\"lamog\");\n    // aList.show();\n    // cout <<aList.size() <<endl;\n    // cout <<endl;\n    // aList.addFront(\"!!!!!\");\n    aList.show();\n    cout <<aList.size() <<endl;\n    \n    cout <<endl;\n    aList.removeFront();\n    aList.show();\n    cout <<aList.size() <<endl;\n\n    aList.removeFront();\n    aList.show();\n    cout <<aList.size() <<endl;\n    // aList.removeBack();\n    // aList.show();\n    \n\n    return 0;\n}\n\nList1::List1() {\n    head = NULL;\n}\nvoid List1::addFront( const string & item ) {\n    try {\n        Node * aNode = new Node;\n        \n        aNode->data = item;\n        aNode->next = head;\n        head = aNode;\n    } catch (exception& e) {\n        cout <<\"Standard exception: \" <<e.what() <<endl;\n    }\n}\nvoid List1::addBack( const string & item ) {\n    try {\n        Node * aNode = new Node;\n        Node * tmpHead = head;\n\n        aNode->data = item;\n        aNode->next = NULL;\n        \n        if (tmpHead != NULL) {\n            while (tmpHead->next != NULL) tmpHead = tmpHead->next;\n            tmpHead->next = aNode;\n        } else head = aNode;\n        \n        // cout <<tmpHead <<endl\n        //      <<tmpHead->data <<endl\n        //      <<tmpHead->next <<endl\n        //      <<aNode <<endl\n        //      <<aNode->data <<endl\n        //      <<aNode->next <<endl <<endl;\n    } catch (exception& e) {\n        cout <<\"Standard exception: \" <<e.what() <<endl;\n    }\n}\nstring List1::removeFront() {\n    if (empty()) die(\"List is empty.\");\n    \n    Node * tmpHead = head;\n    \n    if (tmpHead->next == NULL) {\n        delete tmpHead;\n        head = NULL;\n    }\n}\nstring List1::removeBack() {\n    if (empty()) die(\"List is empty.\");\n}\nbool List1::empty() const {\n    if (head == NULL) return true;\n    return false;\n}\nunsigned List1::size() const {\n    unsigned counter = 0;\n    Node * tmpHead = head;\n    \n    while (tmpHead != NULL) {\n        tmpHead = tmpHead->next;\n        counter++;\n    }\n    \n    return counter;\n}\nvoid List1::show() const {\n    Node * tmpHead = head;\n    \n    while (tmpHead != NULL) {\n        cout <<tmpHead <<endl\n             <<tmpHead->data <<endl\n             <<tmpHead->next <<endl;\n        tmpHead = tmpHead->next;\n    }\n}\n\nbool die( const string & msg ) {\n    // cerr <<endl <<\"Fatal error: \" <<msg <<endl;\n    // exit( EXIT_FAILURE );\n\n    cout <<endl <<\"Fatal error: \" <<msg <<endl;\n    return true;\n}","undoManager":{"mark":95,"position":100,"stack":[[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":76,"column":14},"end":{"row":76,"column":15}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":76,"column":15},"end":{"row":76,"column":16}},"text":"{"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":76,"column":16},"end":{"row":77,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":77,"column":0},"end":{"row":78,"column":0}},"lines":["            "]},{"action":"insertText","range":{"start":{"row":78,"column":0},"end":{"row":78,"column":9}},"text":"        }"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":69,"column":9},"end":{"row":70,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":70,"column":0},"end":{"row":70,"column":8}},"text":"        "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":8},"end":{"row":70,"column":9}},"text":"N"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":9},"end":{"row":70,"column":10}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":10},"end":{"row":70,"column":11}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":11},"end":{"row":70,"column":12}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":12},"end":{"row":70,"column":13}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":13},"end":{"row":70,"column":14}},"text":"*"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":14},"end":{"row":70,"column":15}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":15},"end":{"row":70,"column":16}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":16},"end":{"row":70,"column":17}},"text":"m"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":70,"column":15},"end":{"row":70,"column":17}},"text":"tm"},{"action":"insertText","range":{"start":{"row":70,"column":15},"end":{"row":70,"column":22}},"text":"tmpHead"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":22},"end":{"row":70,"column":23}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":23},"end":{"row":70,"column":24}},"text":"="}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":24},"end":{"row":70,"column":25}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":25},"end":{"row":70,"column":26}},"text":"h"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":26},"end":{"row":70,"column":27}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":27},"end":{"row":70,"column":28}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":28},"end":{"row":70,"column":29}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":29},"end":{"row":70,"column":30}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":70,"column":30},"end":{"row":71,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":71,"column":0},"end":{"row":71,"column":8}},"text":"        "}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":72,"column":12},"end":{"row":72,"column":22}},"text":"head->next"},{"action":"insertText","range":{"start":{"row":72,"column":12},"end":{"row":72,"column":13}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":72,"column":13},"end":{"row":72,"column":14}},"text":"m"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":72,"column":12},"end":{"row":72,"column":14}},"text":"tm"},{"action":"insertText","range":{"start":{"row":72,"column":12},"end":{"row":72,"column":19}},"text":"tmpHead"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":12},"end":{"row":79,"column":13}},"text":"h"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":13},"end":{"row":79,"column":14}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":14},"end":{"row":79,"column":15}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":15},"end":{"row":79,"column":16}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":16},"end":{"row":79,"column":17}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":17},"end":{"row":79,"column":18}},"text":"="}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":18},"end":{"row":79,"column":19}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":19},"end":{"row":79,"column":20}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":20},"end":{"row":79,"column":21}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":21},"end":{"row":79,"column":22}},"text":"w"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":22},"end":{"row":79,"column":23}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":23},"end":{"row":79,"column":24}},"text":"N"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":24},"end":{"row":79,"column":25}},"text":"o"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":25},"end":{"row":79,"column":26}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":26},"end":{"row":79,"column":27}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":79,"column":27},"end":{"row":79,"column":28}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"removeLines","range":{"start":{"row":96,"column":0},"end":{"row":97,"column":0}},"nl":"\n","lines":["        delete tmpHead;"]}]}],[{"group":"doc","deltas":[{"action":"removeLines","range":{"start":{"row":89,"column":0},"end":{"row":92,"column":0}},"nl":"\n","lines":["        ","        while (tmpHead->next != NULL) tmpHead = tmpHead->next;","        tmpHead->next = aNode;"]}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":92,"column":0},"end":{"row":92,"column":8}},"text":"        "},{"action":"insertText","range":{"start":{"row":92,"column":8},"end":{"row":93,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":93,"column":0},"end":{"row":95,"column":0}},"lines":["        while (tmpHead->next != NULL) tmpHead = tmpHead->next;","        tmpHead->next = aNode;"]}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":92,"column":8},"end":{"row":93,"column":0}},"text":"\n"},{"action":"insertText","range":{"start":{"row":93,"column":0},"end":{"row":93,"column":8}},"text":"        "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":8},"end":{"row":93,"column":9}},"text":"i"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":9},"end":{"row":93,"column":10}},"text":"f"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":10},"end":{"row":93,"column":11}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":11},"end":{"row":93,"column":13}},"text":"()"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":12},"end":{"row":93,"column":13}},"text":"t"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":13},"end":{"row":93,"column":14}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":14},"end":{"row":93,"column":15}},"text":"m"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":15},"end":{"row":93,"column":16}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":93,"column":15},"end":{"row":93,"column":16}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":15},"end":{"row":93,"column":16}},"text":"p"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":93,"column":15},"end":{"row":93,"column":16}},"text":"p"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":93,"column":14},"end":{"row":93,"column":15}},"text":"m"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":93,"column":13},"end":{"row":93,"column":14}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":13},"end":{"row":93,"column":14}},"text":"m"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":93,"column":12},"end":{"row":93,"column":14}},"text":"tm"},{"action":"insertText","range":{"start":{"row":93,"column":12},"end":{"row":93,"column":19}},"text":"tmpHead"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":19},"end":{"row":93,"column":20}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":20},"end":{"row":93,"column":21}},"text":"!"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":21},"end":{"row":93,"column":22}},"text":"="}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":22},"end":{"row":93,"column":23}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":23},"end":{"row":93,"column":24}},"text":"N"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":24},"end":{"row":93,"column":25}},"text":"U"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":25},"end":{"row":93,"column":26}},"text":"L"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":26},"end":{"row":93,"column":27}},"text":"L"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":28},"end":{"row":93,"column":29}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":29},"end":{"row":93,"column":30}},"text":"{"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":93,"column":30},"end":{"row":94,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":94,"column":0},"end":{"row":95,"column":0}},"lines":["            "]},{"action":"insertText","range":{"start":{"row":95,"column":0},"end":{"row":95,"column":9}},"text":"        }"}]}],[{"group":"doc","deltas":[{"action":"removeLines","range":{"start":{"row":96,"column":0},"end":{"row":98,"column":0}},"nl":"\n","lines":["        while (tmpHead->next != NULL) tmpHead = tmpHead->next;","        tmpHead->next = aNode;"]}]}],[{"group":"doc","deltas":[{"action":"removeLines","range":{"start":{"row":94,"column":0},"end":{"row":95,"column":0}},"nl":"\n","lines":["            "]},{"action":"insertText","range":{"start":{"row":94,"column":0},"end":{"row":94,"column":62}},"text":"        while (tmpHead->next != NULL) tmpHead = tmpHead->next;"},{"action":"insertText","range":{"start":{"row":94,"column":62},"end":{"row":95,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":95,"column":0},"end":{"row":96,"column":0}},"lines":["        tmpHead->next = aNode;"]}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":94,"column":0},"end":{"row":94,"column":4}},"text":"    "},{"action":"insertText","range":{"start":{"row":95,"column":0},"end":{"row":95,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":9},"end":{"row":96,"column":10}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":10},"end":{"row":96,"column":11}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":11},"end":{"row":96,"column":12}},"text":"l"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":12},"end":{"row":96,"column":13}},"text":"s"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":13},"end":{"row":96,"column":14}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":14},"end":{"row":96,"column":15}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":15},"end":{"row":96,"column":16}},"text":"h"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":16},"end":{"row":96,"column":17}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":17},"end":{"row":96,"column":18}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":18},"end":{"row":96,"column":19}},"text":"d"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":19},"end":{"row":96,"column":20}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":20},"end":{"row":96,"column":21}},"text":"="}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":21},"end":{"row":96,"column":22}},"text":" "}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":22},"end":{"row":96,"column":23}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":23},"end":{"row":96,"column":24}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":96,"column":23},"end":{"row":96,"column":24}},"text":"e"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":96,"column":22},"end":{"row":96,"column":23}},"text":"n"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":22},"end":{"row":96,"column":23}},"text":"a"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":23},"end":{"row":96,"column":24}},"text":"N"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":96,"column":22},"end":{"row":96,"column":24}},"text":"aN"},{"action":"insertText","range":{"start":{"row":96,"column":22},"end":{"row":96,"column":27}},"text":"aNode"}]}],[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":96,"column":27},"end":{"row":96,"column":28}},"text":";"}]}],[{"group":"doc","deltas":[{"action":"removeLines","range":{"start":{"row":72,"column":0},"end":{"row":73,"column":0}},"nl":"\n","lines":["        if (tmpHead != NULL) {"]}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":79,"column":0},"end":{"row":79,"column":9}},"text":"        }"},{"action":"removeLines","range":{"start":{"row":77,"column":0},"end":{"row":79,"column":0}},"nl":"\n","lines":["        } else {","            head = new Node;"]},{"action":"removeText","range":{"start":{"row":76,"column":25},"end":{"row":77,"column":0}},"text":"\n"}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":71,"column":0},"end":{"row":71,"column":4}},"text":"    "},{"action":"removeText","range":{"start":{"row":72,"column":0},"end":{"row":72,"column":4}},"text":"    "},{"action":"removeText","range":{"start":{"row":73,"column":0},"end":{"row":73,"column":4}},"text":"    "},{"action":"removeText","range":{"start":{"row":74,"column":0},"end":{"row":74,"column":4}},"text":"    "},{"action":"removeText","range":{"start":{"row":75,"column":0},"end":{"row":75,"column":4}},"text":"    "},{"action":"removeText","range":{"start":{"row":76,"column":0},"end":{"row":76,"column":4}},"text":"    "}]}],[{"group":"doc","deltas":[{"action":"removeText","range":{"start":{"row":71,"column":0},"end":{"row":71,"column":4}},"text":"    "},{"action":"removeLines","range":{"start":{"row":70,"column":0},"end":{"row":71,"column":0}},"nl":"\n","lines":["        Node * tmpHead = head;"]}]}],[{"group":"doc","deltas":[{"action":"removeLines","range":{"start":{"row":70,"column":0},"end":{"row":71,"column":0}},"nl":"\n","lines":[""]}]}]]},"ace":{"folds":[],"scrolltop":1515,"scrollleft":0,"selection":{"start":{"row":105,"column":4},"end":{"row":110,"column":5},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":93,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1413860160065}