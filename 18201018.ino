int S0, S1, S2;
int S[2], cout;
int A[2], B[2];
void setup() {
  Serial.begin(9600);

  //SWITCH
  pinMode(5, INPUT); //S0
  pinMode(4, INPUT); //S1
  pinMode(3, INPUT); //S2

  //INPUT
  pinMode(7, INPUT); //A[0]
  pinMode(6, INPUT); //A[1]
  pinMode(9, INPUT); //B[0]
  pinMode(8, INPUT); //B[1]

  //OUTPUT
  pinMode(10, OUTPUT); //S[0]
  pinMode(11, OUTPUT); //S[1]
  pinMode(12, OUTPUT); //cout
}

void loop() {
  S0 = digitalRead(5);
  S1 = digitalRead(4);
  S2 = digitalRead(3);

  A[0] = digitalRead(7);
  A[1] = digitalRead(6);
  B[0] = digitalRead(9);
  B[1] = digitalRead(8);

  //S2 S1 S0
  if (S2 == LOW && S1 == LOW && S0 == LOW)
  {
    //A+B
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, cout);
  }
  else if (S2 == LOW && S1 == LOW && S0 == HIGH)
  {
    //A-B
    SUBTRACTOR();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, cout);
  }
  else if (S2 == LOW && S1 == HIGH && S0 == LOW)
  {
    //A-1
    B[0] = HIGH;
    B[1] = HIGH;
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, LOW);
  }
  else if (S2 == LOW && S1 == HIGH && S0 == HIGH)
  {
    //A+1
    B[0] = HIGH;
    B[1] = LOW;
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, cout);
  }
  else if (S2 == HIGH && S1 == LOW && S0 == LOW)
  {
    //A AND B
    AND();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, cout);
  }
  else if (S2 == HIGH && S1 == LOW && S0 == HIGH)
  {
    //A OR B
    OR();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, cout);
  }
  else if (S2 == HIGH && S1 == HIGH && S0 == LOW)
  {
    // NOT A
    NOT();
    digitalWrite(10, A[0]);
    digitalWrite(11, A[1]);
    digitalWrite(12, cout);

  }
  else if (S2 == HIGH && S1 == HIGH && S0 == HIGH)
  {
    // A XOR B
    XOR();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, cout);
  }
}

void FULLADDER()
{
  cout = LOW;
  for (int i = 0; i <= 1; i++)
  {
    int COUNT = 0;
    if (A[i] == HIGH)
    {
      COUNT = COUNT + 1;
      if (B[i] == HIGH)
      {
        COUNT = COUNT + 1;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
      else if (B[i] == LOW)
      {
        COUNT = COUNT + 0;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
    }
    else if (A[i] == LOW)
    {
      COUNT = COUNT + 0;
      if (B[i] == HIGH)
      {
        COUNT = COUNT + 1;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
      else if (B[i] == LOW)
      {
        COUNT = COUNT + 0;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
    }
    if (COUNT == 3)
    {
      S[i] = HIGH;
      cout = HIGH;
    }
    else if (COUNT == 2)
    {
      S[i] = LOW;
      cout = HIGH;
    }
    else if (COUNT == 1)
    {
      S[i] = HIGH;
      cout = LOW;
    }
    else if (COUNT == 0)
    {
      S[i] = LOW;
      cout = LOW;
    }
  }
}

void SUBTRACTOR(){
cout = LOW;
  for (int i = 0; i <= 1; i++)
  {
    int COUNT = 0;
    if (A[i] == HIGH)
    {
      COUNT = COUNT + 1;
      if (B[i] == HIGH)
      {
        COUNT = COUNT + 1;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
      else if (B[i] == LOW)
      {
        COUNT = COUNT + 0;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
    }
    else if (A[i] == LOW)
    {
      COUNT = COUNT + 0;
      if (B[i] == HIGH)
      {
        COUNT = COUNT + 1;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
      else if (B[i] == LOW)
      {
        COUNT = COUNT + 0;
        if (cout == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (cout == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
    }
    if (COUNT == 3)
    {
      S[i] = HIGH;
      cout = HIGH;
    }
    else if (COUNT == 2)
    {
      S[i] = LOW;
      cout = HIGH;
    }
    else if (COUNT == 1)
    {
      S[i] = HIGH;
      cout = LOW;
    }
    else if (COUNT == 0)
    {
      S[i] = LOW;
      cout = LOW;
    }
  }
  
}

void XOR()
{
  for (int i = 0; i <= 1; i++)
  {
    if (A[i] == B[i])
    {
      S[i] = LOW;
    }
    else
    {
      S[i] = HIGH;
    }
  }
  cout = LOW;
}



void NOT()
{
 for(int i=0;i<=1;i++){
  S[i]= A[i]==HIGH?LOW:HIGH;
 }
  cout = LOW;
}

void AND()
{
  for (int i = 0; i <= 1; i++)
  {
    if (A[i] == HIGH && B[i] == HIGH)
    {
      S[i] = HIGH;
    }
    else
    {
      S[i] = LOW;
    }
  }
  cout = LOW;
}

void OR()
{
  for (int i = 0; i <= 1; i++)
  {
    if (A[i] == HIGH || B[i] == HIGH)
    {
      S[i] = HIGH;
    }
    else
    {
      S[i] = LOW;
    }
  }
  cout = LOW;
}
