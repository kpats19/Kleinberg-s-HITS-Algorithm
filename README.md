# Kleinberg-s-HITS-Algorithm


Implement the HITS algorithm as explained in class/Subject notes adhering to the guidelines of
Handout 2. Pay attention to the sequence of update operations and the scaling. For an example of the
Subject notes, you have output for various initialization vectors. You need to implement class or function
hits (e.g. hitsWXYZ. We expect that no two students will have the same last 4 digits, and no student will
use WXYZ (as in characters W, X, Y, Z) either! For an explanation of the arguments see the discussion on
PageRank to follow.
% java hits iterations initialvalue filename
% ./hits iterations initialvalue filename


For the HITS algorithm, you need to print two values not one. Follow the convention of the Subject notes

Base : 0 :A/H[ 0]=0.3333333/0.3333333 A/H[ 1]=0.3333333/0.3333333 A/H[ 2]=0.3333333/0.3333333
Iter : 1 :A/H[ 0]=0.0000000/0.8320503 A/H[ 1]=0.4472136/0.5547002 A/H[ 2]=0.8944272/0.0000000
or for large graphs

Iter : 37
A/H[ 0]=0.0000000/0.0000002
A/H[ 1]=0.0000001/0.0000238
A/H[ 2]=0.0000002/1.0000000
A/H[ 3]=0.0000159/0.0000000
...


