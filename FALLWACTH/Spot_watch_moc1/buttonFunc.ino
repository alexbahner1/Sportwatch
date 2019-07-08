  void checkIfDownButtonIsPressed()
  {
    if (downButtonState != downLastButtonState) 
  {
    if (downButtonState == 0) 
    {
      down=true;
    }
    delay(50);
  }
   downLastButtonState = downButtonState;
  }

void checkIfUpButtonIsPressed()
{
  if (upButtonState != upLastButtonState) 
  {
    if (upButtonState == 0) {
      up=true;
    }
    delay(50);
  }
   upLastButtonState = upButtonState;
}

void checkIfSelectButtonIsPressed()
{
   if (selectButtonState != selectLastButtonState) 
  {
    if (selectButtonState == 0) {
      select=true;
    }
    delay(50);
  }
   selectLastButtonState = selectButtonState;
}

void checkIfBackButtonIsPressed()
{
   if (backButtonState != backLastButtonState) 
  {
    if (backButtonState == 0) {
      back=true;
    }
    delay(50);
  }
   backLastButtonState = backButtonState;
}
