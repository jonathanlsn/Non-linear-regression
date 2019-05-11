//Include of documents
#include "node.h"
#include "tree.h"
#include "forest.h"
#include "matrix.h"

//Include of libraries
#include <iostream>
#include <time.h> 


int main()
{

  //Creation on an environment of work
  /*std::cout<<"Hello World"<<std::endl;*/
  
  
  //Random number taking care of time (change the seed every second)
  std::cout<< "Tests de random" <<std::endl;
  srand(time(NULL));
  int nbgen=rand()%9+1;    //between 1-9
  printf("%d\n",nbgen);    //print the number
  std::cout<< "   "<< std::endl;

  //Creation of boolen
  bool a = true;
  bool b = true;
  bool c = false;
    
 
  //Test of operators
  std::cout<< "Test of operators" <<std::endl;
  std::cout<< std::boolalpha << ((a && b) == 1) <<std::endl; //AND
  std::cout<< std::boolalpha << ((a || c) == 1) <<std::endl; //OR
  std::cout<< std::boolalpha << ((! b) == 0) <<std::endl;    //NOT
  std::cout<< "   "<< std::endl;

  //creation of string of operator
  std::string str="!";
  std::string str1="&&";
  std::string str2="||";


  //Creation of Node
  Node Node4(str);
  Node Node3(str);
  Node Node1(true);
  Node Node2(true);
  

  //Creation of Tree artificial
  Tree Tree1(&Node1);  
  Tree Tree2(&Node3);
  

  //Test of cross
  std::cout<<"Test of cross"<<std::endl;
  int nb_elem=0; //we need to initialise it

  //Creation of Tree artificial
  Node node100(str1);
  Node node101(true,&node100);
  Node node102(false,&node100);
  Tree tree20(&node100);

  //Test of cross and determination on number of elements under a Node
  std::cout << (tree20.cross(tree20.FirstNode(),nb_elem)==false)<<"\t"<<nb_elem<< std::endl;
  nb_elem=0;
  std::cout << (tree20.cross(&node101,nb_elem)==true)<<"\t"<<nb_elem<< std::endl;
  std::cout<< "   "<< std::endl;

  //Verification of parameters
  std::cout<< "Verification des parametres" <<std::endl;
  std::cout<< Node1.bool_values() <<std::endl;
  std::cout<< Node3.values() <<std::endl;
  std::cout<< "   "<< std::endl;

  std::cout<< "Verification of NextNode at nullptr" <<std::endl;
  std::cout<< std::boolalpha << (Node1.NextNode1()==nullptr) <<std::endl;
  std::cout<< std::boolalpha << (Node1.NextNode2()==nullptr) <<std::endl;
  std::cout<< "   "<< std::endl;  

  //Verification des types
  std::cout<< "Verification of types" <<std::endl;
  std::cout<< Node2.type()<<std::endl;
  std::cout<< Node1.type()<<std::endl;
  std::cout<< "   "<< std::endl;  

   //Verification des arbres
  std::cout<< "Verification of tree and it initilisation" <<std::endl;
  std::cout<< Tree1.FirstNode()<<std::endl;
  std::cout<< Tree1.FirstNode() -> type()  <<std::endl;
  std::cout<< Tree1.Fitness() << std::endl;
  std::cout<< Tree1.NbrNode() << std::endl;
  std::cout<< "   "<< std::endl; 


  //test of FatherNode (Kinship)
  Node Node5 (true, &Node4);

  std::cout<< "test de la parenté"<< std::endl;
  std::cout<< (&Node4==(Node5.FatherNode()))<< std::endl;
  std::cout<< (&Node5==(Node4.NextNode1())) <<std::endl;
  std::cout<< "   "<< std::endl; 
 
  //return nullptr
  std::cout<< "test nullptr"<< std::endl;
  int* d =  nullptr;
  std::cout<< std::boolalpha<< (d ==nullptr) << std::endl;
  std::cout<< "   "<< std::endl; 

  //result opeartors
  std::cout<< "result tree operator  not T"<< std::endl;
  Tree Tree3(&Node4);
  std::cout << (Tree3.cross(Tree3.FirstNode(),nb_elem)==false) << std::endl;


  std::cout<< "result tree operator  not F"<< std::endl;
  Node Node7(str);
  Node Node6 (false, &Node7);
  Tree Tree6(&Node7);
  std::cout << (Tree6.cross(Tree6.FirstNode(),nb_elem)==true) << std::endl;

  std::cout<< "result tree operator and FF"<< std::endl;
  Node Node8(str1);
  Node Node9 (false, &Node8);
  Node Node10 (false, &Node8);
  Tree Tree7(&Node8);
  std::cout << (Tree7.cross(Tree7.FirstNode(),nb_elem)==false) << std::endl;

  std::cout<< "resultat tree operator and FV"<< std::endl;
  Node Node11(str1);
  Node Node12 (false, &Node11);
  Node Node13 (true, &Node11);
  Tree Tree8(&Node11);
  std::cout << (Tree8.cross(Tree8.FirstNode(),nb_elem)==false) << std::endl;

  std::cout<< "result tree operator and VF"<< std::endl;
  Node Node14(str1);
  Node Node15 (true, &Node14);
  Node Node16 (false, &Node14);
  Tree Tree9(&Node14);
  std::cout << (Tree9.cross(Tree9.FirstNode(),nb_elem)==false) << std::endl;

  std::cout<< "result tree operator and TT"<< std::endl;
  Node Node17(str1);
  Node Node18 (true, &Node17);
  Node Node19 (true, &Node17);
  Tree Tree10(&Node17);
  std::cout << (Tree10.cross(Tree10.FirstNode(),nb_elem)==true) << std::endl;

  std::cout<< "resultat tree operator or VV"<< std::endl;
  Node Node20(str2);
  Node Node21 (true, &Node20);
  Node Node22 (true, &Node20);
  Tree Tree11(&Node20);
  std::cout << (Tree11.cross(Tree11.FirstNode(),nb_elem)==true) << std::endl;

  std::cout<< "result tree operator or VF"<< std::endl;
  Node Node23(str2);
  Node Node24 (true, &Node23);
  Node Node25 (false, &Node23);
  Tree Tree12(&Node23);
  std::cout << (Tree12.cross(Tree12.FirstNode(),nb_elem)==true) << std::endl;

  std::cout<< "result tree operator or FV"<< std::endl;
  Node Node26(str2);
  Node Node27 (false, &Node26);
  Node Node28 (true, &Node26);
  Tree Tree13(&Node26);
  std::cout << (Tree13.cross(Tree13.FirstNode(),nb_elem)==true) << std::endl;

  std::cout<< "result tree operator or FF"<< std::endl;
  Node Node29(str2);
  Node Node30 (false, &Node29);
  Node Node31 (false, &Node29);
  Tree Tree14(&Node29);
  std::cout << (Tree14.cross(Tree14.FirstNode(),nb_elem)==false) << std::endl;
  std::cout<< " "<< std::endl;


  //Creation complexe tree
  std::cout<< "resultat complexe tree"<< std::endl;
  Node Node32(str1);
  Node Node33(str, &Node32);
  Node Node34(false, &Node33);
  Node Node35(true, &Node32);

  Tree Tree15(&Node32);
  std::cout << (Tree15.cross(Tree15.FirstNode(),nb_elem)==true) << std::endl;
  std::cout<< " "<< std::endl;

  //Test mutation
  Node Node36(str1);
  Tree Tree16(&Node36);
  /*Tree15.mutation();
  std::cout<< "   "<< std::endl;
  std::cout<< "Premiere mutation"<< std::endl;
  Tree15.mutation();
  std::cout<< "   "<< std::endl;
  std::cout<< "Deuxieme mutation"<< std::endl;
  Tree15.mutation();
  std::cout<< "   "<< std::endl;
  std::cout<< "Troisieme mutation"<< std::endl;
  Tree15.mutation();
  std::cout <<"Le nombre de noeud après modification " << Tree15.NbrNode() << std::endl;*/

  //Nouvel arbre


  Node Node37(str1);
  Node Node38(str2,&Node37);
  Node Node39(str1,&Node38);
  Node Node40(str,&Node39);
  Node Node41(false,&Node40);
  Node Node42(true,&Node39);
  Node Node43(str,&Node38);
  Node Node44(true,&Node43);
  Node Node45(str,&Node37);
  Node Node46(false,&Node45);   

  Tree Tree17(&Node37);

/*  std::cout<< "   "<< std::endl;
  std::cout<< "Premiere mutation"<< std::endl;
  Tree17.mutation();
  std::cout<< "   "<< std::endl;
  std::cout<< "Deuxieme mutation"<< std::endl;
  Tree17.mutation();
  std::cout<< "   "<< std::endl;
  std::cout<< "Troisieme mutation"<< std::endl;
  Tree17.mutation();
  std::cout <<"Le nombre de noeud après modification " << Tree17.NbrNode() << std::endl;
*/


  //Creation of forest
  Forest Forest1;
  Forest1.PushBack(Tree2);

  //Test of Pushback
  std::cout <<"Number of tree in forest " << Forest1.nb_elmts()<< std::endl;
  //Forest1.PushBack(Tree3);
  std::cout <<"Number of tree in forest " << Forest1.nb_elmts()<< std::endl;
  std::cout<< " "<< std::endl;

  //Creation of initial tree
  int Nbrmutation =20;
  
  Node Node47(true);
  Tree Tree18(&Node47);
  
 /* for (int i=0; i<Nbrmutation; ++i){
    std::cout<< "   "<< std::endl;
    std::cout<< "mutation"<< i <<std::endl;
    Tree18.mutation();
  }*/


/*  Node Node52 (str1);
  Node Node51(str,&Node52);
  Node Node50(true,&Node51);

  Tree Tree52(&Node52);
  for (int i=0; i<Nbrmutation; ++i){
    std::cout<< "   "<< std::endl;
    std::cout<< "mutation"<< i <<std::endl;
    Tree52.mutation();
    }
*/


  //Fitness
  std::cout<< "Test calcul of fitness"<< std::endl;
  
    //Test fonction Fitness
  Node node1("&&");
  Node node2 (true, &node1);
  Node node3 (true, &node1);
  Tree tree(&node1);
  
  bool y=1;
  tree.calcul_fitness(y);
  std::cout<< "Fitness 1&&1=1 : "<<tree.Fitness()<<std::endl;
  
  bool z=0;
  tree.calcul_fitness(z);
  std::cout<< "Fitness 1&&1=0 : "<<tree.Fitness()<<std::endl;
  
  
  /*
  // Création de la matrice pour une relation x1&&x2=y
  int nLignes=3;
  int nColonnes=3;
  
  int **matrix;
  
  matrix = new int* [ nLignes ];
  for (int i=0; i < nLignes; i++)
    matrix[i] = new int[ nColonnes ];
   
  for (int i=0; i < nLignes; i++)
    for (int j=0; j < nColonnes; j++)
      matrix[i][j] = 0;
      
  matrix[0][0]=1;
  matrix[0][2]=1;
  matrix[1][1]=1;
  matrix[1][2]=1;
  matrix[2][2]=1;
  
  // Affichage 
  for (int i=0; i < nLignes; i++) {
    for (int j=0; j < nColonnes; j++){
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  */
  
  std::cout<< std::endl;

  
  //Creation of matrix
  int tab[]={1,0,0,0,1,0,1,1,1};
  int nligne=3;
  int ncolonne=3;
  Matrix matrix(tab,nligne,ncolonne);

  std::cout<< "tests dimension"<< std::endl;
  matrix.nlignes();
  matrix.ncolonnes();

  std::cout<< "matrix"<< std::endl;
  matrix.show();//Show the matrix

  std::cout<< "tests matrix"<< std::endl;
  std::cout<< matrix.x()[0][0] <<std::endl;
  std::cout<<matrix.y()[0]<<std::endl;;
  
  


  return 0;
}
