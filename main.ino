

String board[6][6]; //board that contains where each curPiece is
int Moves[36][2];
int index;
int kingX = 0;
int kingY = 0;
String puzzleNum;
String whiteMove;
int PieceX;
int PieceY;
String curPiece;
int LEDX;
int LEDY;
int dt;

void availableMoves(){
  index = 0;
  if (curPiece[1] == 'R'){



    
    // check horizontally to the left of the rook
    for (int i = PieceY - 1; i >= 0; i--) {
      if (board[PieceX][i] == "_") {
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
      }
      else{
        if(board[PieceX][i][0] != curPiece[0]){
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
        }
        break;
      }
    }
    //check horizontally to the right of the rook
    for (int i = PieceY + 1; i < 6; i++) {
      if (board[PieceX][i] == "_") {
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
      }
      else{
        if(board[PieceX][i][0] != curPiece[0]){
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
        }
        break;
      }
    }



    // check vertically below the rook
    for (int i = PieceX + 1; i < 6; i++) {
      if (board[i][PieceY] == "_") {
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
      }
      else{
        if(board[i][PieceY][0] != curPiece[0]){
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
        }
        break;
      }
    }
    // check vertically above the rook
    for (int i = PieceX - 1; i >= 0; i--) {
      if (board[i][PieceY] == "_") {
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
      }
      else{
        if(board[i][PieceY][0] != curPiece[0]){
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
        }
        break;
      }
    }

    
  }
   else if (curPiece[1] == 'N'){

    
        // check all possible L-shaped moves
    int rowMoves[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colMoves[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    for (int i = 0; i < 8; i++) {
      int newRow = PieceX + rowMoves[i];
      int newCol = PieceY + colMoves[i];
      
if (newRow >= 0 && newRow < 6 && newCol >= 0 && newCol < 6) { //if move is real, and is on the board
  if (board[newRow][newCol] == "_" || board[newRow][newCol][0] != curPiece[0]) { //if the square it wants to land on is empty or the enemies color (capture)
    Moves[index][0] = newRow;
    Moves[index][1] = newCol;
    index++;
  }
}

    }

    
  }
    else if (curPiece[1] == 'B'){

     // check diagonally top-left to bottom-right
    for (int i = 1; PieceX + i < 6 && PieceY + i < 6; i++) {
      if (board[PieceX + i][PieceY + i] == "_") {
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY + i;
        index++;
      } else {
        if(board[PieceX + i][PieceY + i][0] != curPiece[0]){
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY + i;
        index++;
        }
        break;
      }
    }
    
    // check diagonally top-right to bottom-left
    for (int i = 1; PieceX - i >= 0 && PieceY + i < 6; i++) {
      if (board[PieceX - i][PieceY + i] == "_") {
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY + i;
        index++;
      } else {
        if(board[PieceX - i][PieceY + i][0] != curPiece[0]){
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY + i;
        index++;
        }
        break;
      }
    }
    
    // check diagonally bottom-left to top-right
    for (int i = 1; PieceX + i < 6 && PieceY - i >= 0; i++) {
      if (board[PieceX + i][PieceY - i] == "_") {
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY - i;
        index++;
      } else {
        if(board[PieceX + i][PieceY - i][0] != curPiece[0]){
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY - i;
        index++;
        }
        break;
      }
    }
    
    // check diagonally bottom-right to top-left
    for (int i = 1; PieceX - i >= 0 && PieceY - i >= 0; i++) {
      if (board[PieceX - i][PieceY - i] == "_") {
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY - i;
        index++;
      } else {
        if(board[PieceX - i][PieceY - i][0] != curPiece[0]){
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY - i;
        index++;
        }
        break;
      }
    }
  }
  
    
    else if (curPiece[1] == 'Q'){ // queen moves
    


  //rook moves
    
    // check horizontally to the left of the rook
    for (int i = PieceY - 1; i >= 0; i--) {
      if (board[PieceX][i] == "_") {
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
      }
      else{
        if(board[PieceX][i][0] != curPiece[0]){
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
        }
        break;
      }
    }
    //check horizontally to the right of the rook
    for (int i = PieceY + 1; i < 6; i++) {
      if (board[PieceX][i] == "_") {
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
      }
      else{
        if(board[PieceX][i][0] != curPiece[0]){
        Moves[index][0] = PieceX;
        Moves[index][1] = i;
        index++;
        }
        break;
      }
    }



    // check vertically below the rook
    for (int i = PieceX + 1; i < 6; i++) {
      if (board[i][PieceY] == "_") {
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
      }
      else{
        if(board[PieceX][i][0] != curPiece[0]){
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
        }
        break;
      }
    }
    // check vertically above the rook
    for (int i = PieceX - 1; i >= 0; i--) {
      if (board[i][PieceY] == "_") {
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
      }
      else{
        if(board[i][PieceY][0] != curPiece[0]){
        Moves[index][0] = i;
        Moves[index][1] = PieceY;
        index++;
        }
        break;
      }
    }



    //bishop moves


     // check diagonally top-left to bottom-right
    for (int i = 1; PieceX + i < 6 && PieceY + i < 6; i++) {
      if (board[PieceX + i][PieceY + i] == "_") {
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY + i;
        index++;
      } else {
        if(board[PieceX + i][PieceY + i][0] != curPiece[0]){
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY + i;
        index++;
        }
        break;
      }
    }
    
    // check diagonally top-right to bottom-left
    for (int i = 1; PieceX - i >= 0 && PieceY + i < 6; i++) {
      if (board[PieceX - i][PieceY + i] == "_") {
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY + i;
        index++;
      } else {
        if(board[PieceX - i][PieceY + i][0] != curPiece[0]){
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY + i;
        index++;
        }
        break;
      }
    }
    
    // check diagonally bottom-left to top-right
    for (int i = 1; PieceX + i < 6 && PieceY - i >= 0; i++) {
      if (board[PieceX + i][PieceY - i] == "_") {
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY - i;
        index++;
      } else {
        if(board[PieceX + i][PieceY - i][0] != curPiece[0]){
        Moves[index][0] = PieceX + i;
        Moves[index][1] = PieceY - i;
        index++;
        }
        break;
      }
    }
    
    // check diagonally bottom-right to top-left
    for (int i = 1; PieceX - i >= 0 && PieceY - i >= 0; i++) {
      if (board[PieceX - i][PieceY - i] == "_") {
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY - i;
        index++;
      } else {
        if(board[PieceX - i][PieceY - i][0] != curPiece[0]){
        Moves[index][0] = PieceX - i;
        Moves[index][1] = PieceY - i;
        index++;
        }
        break;
      }
    }


    
  }
    else if (curPiece[1] == 'K'){

        for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        int x = PieceX+i;
        int y = PieceY+j;
        if (x >= 0 && x < 6 && y >= 0 && y < 6 && board[x][y][0] != curPiece[0]) {
          Moves[index][0] = x;
          Moves[index][1] = y;
          index++;
        }
      }
    }

    
  }
    else if (curPiece[1] == 'P'){
      if (curPiece[0] == 'w'){
        if (board[PieceX - 1][PieceY] == "_"){
        Moves[index][0] = PieceX-1;
        Moves[index][1] = PieceY;
        index++;
        }
        //take to the left
        if (board[PieceX - 1][PieceY - 1] != "_" && board[PieceX - 1][PieceY - 1][0] == 'b'){
          Moves[index][0] = PieceX - 1;
          Moves[index][1] = PieceY - 1;
          index++;
        }
        //take to the right
        if (board[PieceX - 1][PieceY + 1] != "_" && board[PieceX - 1][PieceY + 1][0] == 'b'){
          Moves[index][0] = PieceX - 1;
          Moves[index][1] = PieceY + 1;
          index++;
        }
      }
      else if (curPiece[0] == 'b'){
        if(board[PieceX + 1][PieceY] == "_"){
        Moves[index][0] = PieceX+1;
        Moves[index][1] = PieceY;
        index++;
        }
        //take to the left
        if (board[PieceX + 1][PieceY - 1] != "_" && board[PieceX + 1][PieceY - 1][0] == 'w'){
          Moves[index][0] = PieceX + 1;
          Moves[index][1] = PieceY - 1;
          index++;
        }
        //take to the right
        if (board[PieceX + 1][PieceY + 1] != "_" && board[PieceX + 1][PieceY + 1][0] == 'w'){
          Moves[index][0] = PieceX + 1;
          Moves[index][1] = PieceY + 1;
          index++;
        }
      }
      }








  Serial.print("Available moves for curPiece ");
  Serial.print(curPiece);
  Serial.print(" at position (");
  Serial.print(PieceX);
  Serial.print(",");
  Serial.print(PieceY);
  Serial.println("):");





  for (int i = 0; i < index; i++) {
    Serial.print("(");
    Serial.print(Moves[i][0]);
    Serial.print(",");
    Serial.print(Moves[i][1]);
    Serial.println(")");
  }
int lenList = index;
Serial.print("Available moves: ");
Serial.println(lenList);

  
  
}





void printBoard() { //just prints the board
  Serial.println("\n\n");
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      Serial.print(board[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}


void putPiece(String curPiece, int xCor, int yCor){ //place a curPiece on a square
  board[xCor][yCor] = curPiece; //input the curPiece, the x coordinate and the y coordinate
}


void delPiece(int xCor, int yCor){ //remove a curPiece from a certain square
  board[xCor][yCor] = "_"; //input the x and y coordinate
}


//assuming we know the position of the king (kingX, kingY)
bool isKingInCheck(String kingColor) {
   for(int i = 0; i < 6; i++){ //PieceX
   for(int j = 0; j < 6; j++){ //PieceY
      if(board[i][j] == kingColor){
        kingX = i;
        kingY = j;
      }
    }
  }
  //iterate through all the opponent's curPieces
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (board[i][j] != "_" && board[i][j][0] != kingColor[0]) {
        //if the opponent's curPiece can attack the king, return true
        if (canAttack(i, j, kingX, kingY)) {
          return true;
        }
      }
    }
  }
  //if no curPiece can attack the king, return false
  return false;
}

//helper function to check if a curPiece can attack another curPiece
bool canAttack(int curPieceX, int curPieceY, int targetX, int targetY) {
  //get the available moves for the curPiece
  availableMoves();
  //iterate through the available moves
  for (int i = 0; i < index; i++) {
    //if the curPiece can attack the target curPiece, return true
    if (Moves[i][0] == targetX && Moves[i][1] == targetY) {
      return true;
    }
  }
  //if the curPiece cannot attack the target curPiece, return false
  return false;
}








void lightUp(){
  for(int i = 0; i < index; i++){
    LEDX = Moves[i][0];
    LEDY = Moves[i][1];
    if(LEDX == 0 && LEDY == 0){
      digitalWrite(6, HIGH);
      Serial.println("WORKS");
    }
    else if(LEDX == 0 && LEDY == 1){
      digitalWrite(5, HIGH);
    }
    else if(LEDX == 0 && LEDY == 2){
      digitalWrite(4, HIGH);
    }
    else if(LEDX == 0 && LEDY == 3){
      digitalWrite(3, HIGH);
    }
    else if(LEDX == 0 && LEDY == 4){
      digitalWrite(2, HIGH);
    }
    else if(LEDX == 0 && LEDY == 5){
      digitalWrite(53, HIGH);
    }
    else if(LEDX == 1 && LEDY == 0){
      digitalWrite(52, HIGH);
    }
    else if(LEDX == 1 && LEDY == 1){
      digitalWrite(51, HIGH);
    }
    else if(LEDX == 1 && LEDY == 2){
      digitalWrite(50, HIGH);
    }
    else if(LEDX == 1 && LEDY == 3){
      digitalWrite(49, HIGH);
    }
    else if(LEDX == 1 && LEDY == 4){
      digitalWrite(48, HIGH);
    }
    else if(LEDX == 1 && LEDY == 5){
      digitalWrite(47, HIGH);
    }
    else if(LEDX == 2 && LEDY == 0){
      digitalWrite(46, HIGH);
    }
    else if(LEDX == 2 && LEDY == 1){
      digitalWrite(45, HIGH);
    }
    else if(LEDX == 2 && LEDY == 2){
      digitalWrite(44, HIGH);
    }
    else if(LEDX == 2 && LEDY == 3){
      digitalWrite(43, HIGH);
    }
    else if(LEDX == 2 && LEDY == 4){
      digitalWrite(42, HIGH);
    }
    else if(LEDX == 2 && LEDY == 5){
      digitalWrite(41, HIGH);
    }
    else if(LEDX == 3 && LEDY == 0){
      digitalWrite(40, HIGH);
    }
    else if(LEDX == 3 && LEDY == 1){
      digitalWrite(39, HIGH);
    }
    else if(LEDX == 3 && LEDY == 2){
      digitalWrite(38, HIGH);
    }
    else if(LEDX == 3 && LEDY == 3){
      digitalWrite(37, HIGH);
    }
    else if(LEDX == 3 && LEDY == 4){
      digitalWrite(36, HIGH);
    }
    else if(LEDX == 3 && LEDY == 5){
      digitalWrite(35, HIGH);
    }
    else if(LEDX == 4 && LEDY == 0){
      digitalWrite(34, HIGH);
    }
    else if(LEDX == 4 && LEDY == 1){
      digitalWrite(33, HIGH);
    }
    else if(LEDX == 4 && LEDY == 2){
      digitalWrite(32, HIGH);
    }
    else if(LEDX == 4 && LEDY == 3){
      digitalWrite(31, HIGH);
    }
    else if(LEDX == 4 && LEDY == 4){
      digitalWrite(30, HIGH);
    }
    else if(LEDX == 4 && LEDY == 5){
      digitalWrite(29, HIGH);
    }
    else if(LEDX == 5 && LEDY == 0){
      digitalWrite(28, HIGH);
    }
    else if(LEDX == 5 && LEDY == 1){
      digitalWrite(26, HIGH);
    }
    else if(LEDX == 5 && LEDY == 2){
      digitalWrite(25, HIGH);
    }
    else if(LEDX == 5 && LEDY == 3){
      digitalWrite(24, HIGH);
    }
    else if(LEDX == 5 && LEDY == 4){
      digitalWrite(10, HIGH);
    }
    else if(LEDX == 5 && LEDY == 5){
      digitalWrite(9, HIGH);
    }





    
  }
}



void shutOff(){
for(int i = 0; i < 54; i++){
  digitalWrite(i, LOW);
}
}


void loadingScreen(){
  dt = 50;
  digitalWrite(9, HIGH);
  delay(dt);
  digitalWrite(10, HIGH);
  delay(dt);
  for(int i = 24; i < 53; i++){
    digitalWrite(i, HIGH);
    delay(dt);
  }
  digitalWrite(53, HIGH);
  delay(dt);
  for(int i = 2; i < 7; i++){
    digitalWrite(i, HIGH);
    delay(dt); 
  }

  
  
  digitalWrite(9, LOW);
  delay(dt);
  digitalWrite(10, LOW);
  delay(dt);
  for(int i = 24; i < 53; i++){
    digitalWrite(i, LOW);
    delay(dt);
  }
  digitalWrite(53, LOW);
  delay(dt);
  for(int i = 2; i < 7; i++){
    digitalWrite(i, LOW);
    delay(dt); 
  }
}

void loadingScreenExplode(){
  dt = 200;
  digitalWrite(43, HIGH);
  digitalWrite(44, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  delay(dt);
  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(51, HIGH);
  digitalWrite(48, HIGH);
  digitalWrite(49, HIGH);
  digitalWrite(50, HIGH);
  digitalWrite(36, HIGH);
  digitalWrite(42, HIGH);
  delay(dt);
  for(int i = 0; i < 54; i++){
    digitalWrite(i, HIGH);
  }
  delay(dt);


  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  delay(dt);
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  digitalWrite(39, LOW);
  digitalWrite(45, LOW);
  digitalWrite(51, LOW);
  digitalWrite(48, LOW);
  digitalWrite(49, LOW);
  digitalWrite(50, LOW);
  digitalWrite(36, LOW);
  digitalWrite(42, LOW);
  delay(dt);
  for(int i = 0; i < 54; i++){
    digitalWrite(i, LOW);
  }
  delay(dt);
}
  



  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
 pinMode(53, OUTPUT); //f6
  pinMode(2, OUTPUT); //e6
  pinMode(3, OUTPUT); //d6
  pinMode(4, OUTPUT); //c6
  pinMode(5, OUTPUT); //b6
  pinMode(6, OUTPUT); //a6
  
  pinMode(9, OUTPUT); //f1
  pinMode(10, OUTPUT); //e1
  pinMode(24, OUTPUT); //d1
  pinMode(25, OUTPUT); //c1
  pinMode(26, OUTPUT); //b1
  pinMode(28, OUTPUT); //a1
  
  pinMode(29, OUTPUT); //f2
  pinMode(30, OUTPUT); //e2
  pinMode(31, OUTPUT); //d2
  pinMode(32, OUTPUT); //c2
  pinMode(33, OUTPUT); //b2
  pinMode(34, OUTPUT); //a2
  
  pinMode(35, OUTPUT); //f3
  pinMode(36, OUTPUT); //e3
  pinMode(37, OUTPUT); //d3
  pinMode(38, OUTPUT); //c3
  pinMode(39, OUTPUT); //b3
  pinMode(40, OUTPUT); //a3
  
  pinMode(41, OUTPUT); //f4
  pinMode(42, OUTPUT); //e4
  pinMode(43, OUTPUT); //d4
  pinMode(44, OUTPUT); //c4
  pinMode(45, OUTPUT); //b4
  pinMode(46, OUTPUT); //a4
  
  pinMode(47, OUTPUT); //f5
  pinMode(48, OUTPUT); //e5
  pinMode(49, OUTPUT); //d5
  pinMode(50, OUTPUT); //c5
  pinMode(51, OUTPUT); //b5
  pinMode(52, OUTPUT); //a5

  
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) { //makes the board
      board[i][j] = "_"; 
    }
  }







delay(1000);
for(int i = 0; i < 5; i++){
Serial.println("\n");
}



  Serial.println("What puzzle?");
}



void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
        puzzleNum = Serial.readStringUntil('\n');}
  else{
    loadingScreenExplode();
  }
  if (puzzleNum == "17"){
    while(true){
      //put curPieces where they belong
      putPiece("wK",5 ,4);
      putPiece("wP",4 ,5);
      putPiece("wP",4 ,4);
      putPiece("wP",4 ,3);
      putPiece("wP",4 ,2);
      putPiece("wN",3 ,1);
      putPiece("wQ",3 ,4);
      
      putPiece("bK",0 ,0);
      putPiece("bR",0 ,3);
      putPiece("bB",1 ,4);
      putPiece("bP",1 ,0);
      putPiece("bP",1 ,1);
      putPiece("bP",1 ,2);
      putPiece("bR",3 ,0);
      putPiece("bQ",4 ,0);
      
      //print board
      printBoard();
      Serial.println("Your move:  ");

      
      while(true){
        
        if(Serial.available()){
        shutOff();
        whiteMove = Serial.readStringUntil('\n');
        if(whiteMove == "Nxc5+" || whiteMove == "Nxc5" || whiteMove == "Nc5" || whiteMove == "Nc5+")
        {delPiece(3,1); //get rid of knights original spot
        putPiece("wN", 1, 2);
        delPiece(0, 0);
        putPiece("bK", 0, 1);
        Serial.println("Correct! Black plays: Kb6");
        printBoard();
          break;}
          
          else if(whiteMove == "move"){
          Serial.println("What is the square X?");
          while(true){
            if(Serial.available()){
            PieceX = Serial.readStringUntil('\n').toInt();
            break;}
          }
          Serial.println("What is the square Y?");
          while(true){
            if(Serial.available()){
            PieceY = Serial.readStringUntil('\n').toInt();
            break;}
          }
          curPiece = board[PieceX][PieceY];
          availableMoves();
          lightUp();
          Serial.println("Your move:  ");}
         


        else{Serial.println("Wrong. Try again.");}

        }

      }


      while(true){

        if(Serial.available()){
        shutOff();
        whiteMove = Serial.readStringUntil('\n');
        if(whiteMove == "Na4+" || whiteMove == "Na4")
        {delPiece(1,2); //get rid of knights original spot
        putPiece("wN",2 ,0 );
        delPiece(0, 1);
        putPiece("bK", 0, 0);
        Serial.println("Correct! Black plays: Ka6");
        printBoard();
          break;}

          else if(whiteMove == "move"){
          Serial.println("What is the square X?");
          while(true){
            if(Serial.available()){
            PieceX = Serial.readStringUntil('\n').toInt();
            break;}
          }
          Serial.println("What is the square Y?");
          while(true){
            if(Serial.available()){
            PieceY = Serial.readStringUntil('\n').toInt();
            break;}
          }
          curPiece = board[PieceX][PieceY];
          availableMoves();
          lightUp();
          Serial.println("Your move:  ");}


          
        else{Serial.println("Wrong. Try again.");}
      }

      }


      while(true){

        if(Serial.available()){
          shutOff();
        whiteMove = Serial.readStringUntil('\n');
        if(whiteMove == "Qb6" || whiteMove == "Qb6+")
        {delPiece(3,4); //get rid of knights original spot
        delPiece(0, 3);
        putPiece("bR", 0, 1);
        Serial.println("Correct! Black plays: Rxb6");
        printBoard();
          break;}

          else if(whiteMove == "move"){
          Serial.println("What is the square X?");
          while(true){
            if(Serial.available()){
            PieceX = Serial.readStringUntil('\n').toInt();
            break;}
          }
          Serial.println("What is the square Y?");
          while(true){
            if(Serial.available()){
            PieceY = Serial.readStringUntil('\n').toInt();
            break;}
          }
          curPiece = board[PieceX][PieceY];
          availableMoves();
          lightUp();
          Serial.println("Your move:  ");}

          
        else{Serial.println("Wrong. Try again.");}
      }

      }


      Serial.println("Rxb6");
      while(true){

        if(Serial.available()){
          shutOff();
        whiteMove = Serial.readStringUntil('\n');
        if(whiteMove == "Nc5" || whiteMove == "Nc5+" || whiteMove == "Nc5#")
        {delPiece(2,0);
        putPiece("wN", 1, 2);
        Serial.println("You finished the puzzle");
 }

          else if(whiteMove == "move"){
          Serial.println("What is the square X?");
          while(true){
            if(Serial.available()){
            PieceX = Serial.readStringUntil('\n').toInt();
            break;}
          }
          Serial.println("What is the square Y?");
          while(true){
            if(Serial.available()){
            PieceY = Serial.readStringUntil('\n').toInt();
            break;}
          }
          curPiece = board[PieceX][PieceY];
          availableMoves();
          lightUp();
          Serial.println("Your move:  ");}

        
        else{Serial.println("Wrong. Try again.");}
      }

      }
      
      

      

      
    }
  }

}
