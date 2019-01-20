//Nilesh Agarwal
//@nilesh97

#include <vector>
#include <iostream>

using namespace std;

typedef std::vector<int> V1D;
typedef std::vector<V1D> V2D;

void PrintVector2D(const V2D & v)
{
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[i].size(); ++j){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
  int dimentions;
  int size_of_population;
  int flag;
  int dlag;
  int rank;
  int counter;
  int temp = 0, a = 0;

  cin >> dimentions;
  cin >> size_of_population;

  V2D v(size_of_population,V1D(dimentions));

  for (int i=0; i<v.size(); i++){
    for (int j=0; j<v[i].size(); j++){
        cin >> v[i][j];
    }
  }

//  cout << "\n\nThe original matrix is \n\n";
//  PrintVector2D(v);
//  cout << "\n\n-----------\n\n";
  rank = 1;

  while (v.size()!=0){
    int array_domination_count[v.size()];
    int array_rank[v.size()];
    int array_pos[v.size()];

//    cout << "\n\nThe original matrix is \n\n";
//    PrintVector2D(v);
//    cout << "\n\n-----------\n\n";

    for (int i=0; i<v.size(); i++){
      array_domination_count[i] = 0;
      for (int j=0; j<v.size(); j++){
        flag = 0;
        dlag = 0;
        for (int k=0; k<v[i].size(); k++){
//          cout << v[i][k] << " || " << v[j][k] << endl;
          if (v[i][k]>=v[j][k])
            flag++;
//            cout << flag << " || " << endl;

          if (v[i][k]>v[j][k])
            dlag++;
//            cout << dlag << " || " << endl;
        }
//      cout << flag << " || " << dlag << " || " << endl;
        if (flag >= dimentions && dlag>=1){
          array_domination_count[i] = array_domination_count[i] + 1;
        }
      }
    }

// --------Prints The Domination Count----------
//    for (int i=0; i<v.size(); i++){
//      cout << array_domination_count[i] << " || " << endl;
//    }
    temp = v.size();
    counter = 0;
    for (int i=0; i<temp; i++){
      if (array_domination_count[i]==0){
        array_rank[i]=rank;
//        cout << " Rank Is --> " << rank << endl;
        array_pos[counter]=i;
        counter++;
      }
    }
//        for (int i=0; i<counter; i++){
//          cout << array_pos[i] << " || " << endl;
//        }
    cout << "\n\n-----------\n\n" ;
    for (int i=0; i<counter; i++){
      for (int j=0; j<v[i].size(); j++){
        cout << v[array_pos[i]][j] << " ";
      }
      cout << endl;
      cout << "Rank Is :: " << rank << endl;
    }

    for (int i=0; i<counter; i++){
      v.erase(v.begin()+array_pos[i]-i);
    }
  rank = rank + 1;
//    cout << " Size Is -- " << v.size() << endl;
// --------Prints The Rank Count----------
//  for (int i=0; i<v.size(); i++){
//    cout << array_rank[i] << " || ";
//  }
//PrintVector2D(v);
}


//    cout << v.size() << " || " << endl;
return 0;
}
