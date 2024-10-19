int * * matDyn;

int * * mallocDeMatriceDynamique (int n);
void freeDeMatriceDynamique (int * * mat, int n);
void displayMatDyn(int * * mat, int n);
int * * InitMat(int * * mat, int n);
int nbVoisinDuSommeti (int * * mat, int ligne,int n);
void WriteInFile (int * * mat, int n);
G createANewGraph(int n);
int * * BuildAtRandomAGraph(int * * mat, int n);
