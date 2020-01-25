//
//  main.cpp
//  Vec2D
//
//  Created by Marcus Jian on 2019/12/29.
//  Copyright © 2019 Marcus Jian. All rights reserved.
//

#include <iostream>
#include "Vec2D.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    Vec2D v1(1,0);
    Vec2D v2(0,1);
    cout<<v1.Dot(v2)<<endl;
    cout<<v1.Mag()<<endl;
    cout<<v2.GetUnitVec()<<endl;
    cout<<v1.ProjectOnto(v2)<<endl;
    cout<<v1.AngleBetween(v2)<<endl;
    return 0;
}
