#include <iostream>
using namespace std;

// initialize linked list
struct node {
  // establish data variable
  char data;
  // establish link variable
  node *link;
};

// check to see if the there is a duplicate element in the chosen set
bool elementOf(char newElement, node *set) {
  // establish bool found
  bool found;

  // copy the set
  node *ptr = set;
  found = false;

  // Search the set for the given element
  while (ptr != NULL && !found) {
    // if a duplicate is found in the set, return found
    if (ptr->data == newElement) {
      found = true;
      // else continue traveling the set
    } else {
      ptr = ptr->link;
    }
  }
  return found;
}

// add to the set
void push(char newElement, node *&head) {
  // create the node for the element to be put in
  node *newNode = new node;

  // set the new node's data as the inputted data
  newNode->data = newElement;
  newNode->link = NULL;

  // if there is no head, set the new node as the head
  if (head == NULL) {
    head = newNode;
  }
  // else travel to the end of the set and add the new node to the end
  else {
    // create linked list traversal node
    node *ptr = head;
    // travel to the end of the node
    while (ptr->link != NULL) {
      ptr = ptr->link;
    }
    // add node to the end of the set
    ptr->link = newNode;
  }
}

// create new set
node *createSet() {
  // creates a set
  node *first = new node;
  first = NULL;

  // character value
  char newElement;

  // input the character value
  cin >> newElement;

  // Until '!' is entered, keep inputting more elements
  while (newElement != '!') {
    // if there isn't a duplicate of the input element in the set, add it to the
    // set
    if (!elementOf(newElement, first)) {
      // add the element to the set
      push(newElement, first);
    }
    // input a new element
    cin >> newElement;
  }
  // return the set
  return first;
}

// creat the universal set
node *createUniversal(node *First, node *Second) {
  // create the resulting set of the difference of the two sets
  node *universal = new node;

  // create the traversal node and set it to the first set
  node *ptr = First;

  // add the first set to the universal set
  // traverse the set
  while (ptr != NULL) {
    // add the current data to the universal set
    push(ptr->data, universal);
    // link traversal
    ptr = ptr->link;
  }

  // set the traversal node to the second set
  ptr = Second;

  // Add all elements of the second set to the universal set that are not
  // already there traverse the set
  while (ptr != NULL) {
    // if the data is not in both sets, add it to the universal set
    if (!elementOf(ptr->data, First)) {
      // add the data to the end of the set
      push(ptr->data, universal);
    }
    // linked list traversal
    ptr = ptr->link;
  }

  // return the resulting set
  return universal;
}

// output the set (used for testing)
void print(node *set) {
  // create traversal node
  node *ptr = set;

  // If the set is empty, output "Empty set"
  if (ptr == NULL) {
    // output "Emty set"
    cout << "Empty set" << endl;
  }

  // traverse to the next node
  ptr = ptr->link;

  // Output an open bracket
  cout << "{";
  // traverse to the end of the set
  while (ptr != NULL) {
    // output the data of the current node
    cout << ptr->data;
    // move to the next node
    ptr = ptr->link;
    // if it's not the end of the set, output a comma and a space
    if (ptr != NULL) {
      cout << ", ";
    }
  }
  // output a closing bracket
  cout << "}" << endl;
}

// calculate the difference of the sets (take set A and check if any element of
// A is an element of B)
node *difference(node *First, node *Second) {
  // create the resulting set of the difference of the two sets
  node *setDiff = new node;

  // create the traversal node
  node *ptr = First;

  // find the difference of the sets
  while (ptr != NULL) {
    // if the data is not in both sets, add it to the difference of the sets
    if (!elementOf(ptr->data, Second)) {
      // add the data to the end of the set
      push(ptr->data, setDiff);
    }
    // linked list traversal
    ptr = ptr->link;
  }

  // return the resulting set
  return setDiff;
}

// output the difference of the sets
void printDiff(node *set) {
  // create traversal node
  node *ptr = set;

  // if the set is empty, output "Empty set"
  if (ptr == NULL) {
    // output "Empty set"
    cout << "Empty set" << endl;
  }

  // output "The first set inus the second set is: {"
  cout << "The first set minus the second set is: {";

  // traverse to the next node
  ptr = ptr->link;

  // traverse to the set
  while (ptr != NULL) {
    // output the data of the current node
    cout << ptr->data;
    // linked list traversal
    ptr = ptr->link;
    // If not at the end of the list, output ", "
    if (ptr != NULL) {
      // output ", "
      cout << ", ";
    }
  }
  // output "}" and skip down two lines
  cout << "}\n" << endl;
}

// calculate the disjoint of the sets (returns true if there is nothing in
// common between the sets)
bool is_disjoint(node *First, node *Second) {
  // create the traversal node
  node *ptr = First;

  // create the boolean found
  bool found = true;

  // node traversal
  while (ptr != NULL) {
    // if no elements of the first set are found in the second set, the sets are
    // disjoint
    if (elementOf(ptr->data, Second)) {
      // the element wasn't found in the seond set
      found = false;
    }
    // node traversal
    ptr = ptr->link;
  }

  // return found status
  return found;
}

// print the disjoint status of the two sets
void print_disjoint(bool status) {
  // if the sets are not disjoint, tell the user
  if (status == false) {
    // output "The two sets are not disjoint"
    cout << "The two sets are not disjoint" << endl;
  }
  // if the sets are disjoint, tell the user
  else {
    // output "The two sets are disjoint"
    cout << "The two sets are disjoint" << endl;
  }
  // move down one line
  cout << endl;
}

// calculate the cardinality
int cardinality(node *set) {
  // create traversal node
  node *ptr = set;
  // create the count value
  int count = 0;
  // traverse the set
  while (ptr != NULL) {
    // count how many data points are in the set
    count++;
    // linked list traversal
    ptr = ptr->link;
  }

  // return the number of data points in the set
  return count;
}

// display the menu
void display_menu() {
  // output the menu
  cout << " ================ " << endl;
  cout << "1. difference\n";
  cout << "2. disjoint\n";
  cout << "3. cardinality\n";
  cout << "4. Quit\n";
  cout << " ================ \n" << endl;
}

// output the set options
void setOptions() {
  cout << "\n ================ " << endl;
  cout << "1. Set A" << endl;
  cout << "2. Set B" << endl;
  cout << "3. The empty set" << endl;
  cout << "4. The universal set" << endl;
  cout << " ================ \n" << endl;
}

// select a set option
node *chooseSet(node *A, node *B, node *E, node *U) {
  int choice = 0;

  // while none of the options are selected
  while (choice != 1 || 2 || 3 || 4) {
    // input the choice
    cin >> choice;

    // use switch function for user to select which set they want to use
    switch (choice) {
    // select set A
    case 1:
      return A;
      break;

    // select set B
    case 2:
      return B;
      break;

    // select the empty set
    case 3:
      return E;
      break;

    // select the universal set
    case 4:
      return U;
      break;

    // output invalid input
    default:
      cout << "Invalid option, try again" << endl;
    }
  }
}

// make the menu choice
void menu(node *First, node *Second, node *empty, node *universal) {
  // create choice variables
  int choice, choice2;

  // create size variable
  int size;

  // create sets to select
  node *A;
  node *B;

  // output the dividing line
  cout << "------------------------------------------------------" << endl;

  // prompt the user to enter a menu choice
  cout << "Enter a menu (1, 2, 3, 4): ";
  // input a menu choice
  cin >> choice;
  // move down a line
  cout << endl;

  // make your menu selection
  // If the user selects menu item 4, end the program
  while (choice != 4) {
    // use switch function for user to select a menu option
    switch (choice) {
    // select difference
    case 1:
      // output set options
      setOptions();
      // prompt the user to select which set they want to use
      cout << "Choose the first set: " << endl;
      // select which set will be used
      A = chooseSet(First, Second, empty, universal);

      // prompt the user to select which set they want to use
      cout << "Choose the second set: " << endl;
      // select which set will be used
      B = chooseSet(First, Second, empty, universal);

      // output difference of the selected sets
      printDiff(difference(A, B));
      break;

    // select disjoint status
    case 2:
      // output set options
      setOptions();
      // prompt the user to select which set they want to use
      cout << "Choose the first set: " << endl;
      // select which set will be used
      A = chooseSet(First, Second, empty, universal);

      // prompt the user to select which set they want to use
      cout << "Choose the second set: " << endl;
      // select which set will be used
      B = chooseSet(First, Second, empty, universal);
      // output disjoint status of the selected sets
      print_disjoint(is_disjoint(A, B));
      break;

    // select cardinality
    case 3:
      // output options
      cout << "Do you want the cardinality of a set or of a set difference?"
           << endl;
      cout << " ================ " << endl;
      cout << "1. Set" << endl;
      cout << "2. The difference of two sets" << endl;
      cout << " ================ \n" << endl;
      // set choice2 to 0;
      choice2 = 0;
      // while neither of the options are selected
      while (choice2 != 1 && choice2 != 2) {
        // input choice2
        cin >> choice2;

        // use switch function for user to select a presented option
        switch (choice2) {
        // find the cardinality of one set
        case 1:
          // output set options
          setOptions();
          // prompt the user to select which set they want to use
          cout << "Which set?" << endl;
          // select which set will be used
          A = chooseSet(First, Second, empty, universal);

          // set size value to the cardinality value
          if (A == universal) {
            size = cardinality(A) - 1;
          } else {
            size = cardinality(A);
          }

          // output the cardinality
          cout << "\nThe cardinality of the selected set is: " << size << endl;
          break;

        // find the cardinality of a difference of sets
        case 2:
          // output set options
          setOptions();
          // prompt the user to select which set they want to use
          cout << "Choose the first set: " << endl;
          // select which set will be used
          A = chooseSet(First, Second, empty, universal);

          // prompt the user to select which set they want to use
          cout << "Choose the second set: " << endl;
          // select which set will be used
          B = chooseSet(First, Second, empty, universal);

          // set size value to the cardinality value
          if ((A == universal) || (B == universal)) {
            size = cardinality(difference(A, B)) - 2;
          } else {
            size = cardinality(difference(A, B)) - 1;
          }
          if (size < 0) {
            size++;
          }

          // output cardinality
          cout
              << "\nThe cardinality of the difference of the selected sets is: "
              << size << endl;
          break;

        // output invalid option
        default:
          cout << "Invalid option, try again" << endl;
        }
      }
      break;

    default:
      // output invalid option
      cout << "This isnt a valid option try again.\n" << endl;
    }

    // output the dividing line
    cout << "------------------------------------------------------" << endl;

    // display menu options
    display_menu();

    // prompt the user to enter a menu choice
    cout << "Enter a menu (1, 2, 3, 4): ";
    // input a menu choice
    cin >> choice;
    // move down a line
    cout << endl;
  }
  // output end of program notification
  cout << "End of program." << endl;
}

// main function
int main() {
  // display the menu
  display_menu();

  // create setA
  // prompt the user for elements of Set A
  cout << "-->Enter the elements for a set A. Use '!' to stop" << endl;
  // create the empty set A
  node *setA;
  // fill Set A
  setA = createSet();
  // move down two lines
  cout << "\n" << endl;

  // create set B
  // prompt the user for elements of Set B
  cout << "-->Enter the elements for a set B. Use '!' to stop" << endl;
  // create the empty set B
  node *setB;
  // fill Set B
  setB = createSet();
  // move down two lines
  cout << "\n" << endl;

  // create the empty universal set
  node *universal;
  // fill universal set
  universal = createUniversal(setA, setB);

  // create the empty set
  node *empty = NULL;

  // make a menu choice
  menu(setA, setB, empty, universal);

  return 0;
}