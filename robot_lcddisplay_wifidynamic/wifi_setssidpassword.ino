/*void wificommunication()
{

  Serial.print("Enter your WiFi credentials.\n");
  Serial.print("SSID: ");
  while (Serial.available() == 0) {
    // wait
  }
  Serial.readBytesUntil(10, ssid, 50);
  Serial.print(ssid);
Serial.print("donessid");

  Serial.print("PASS: ");
  while (Serial.available() == 0) {
    // wait
  }
  Serial.readBytesUntil(10, pass, 50);
  Serial.print(pass);
 Serial.print("donepass");


  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting....");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void commandcommunication()
{
  if(Serial.available()>0)
  {
    String input = Serial.readStringUntil('\n');
    if(input.startWith("SSID:")){
      String ssid = input.substring(5);
    }
    else if(input.startWith("password:"))
    {
      String password = input.substring(9);
    }
  }
}*/

void getwifissid()
{
    if(Serial.available()>0)
  {
    String input = Serial.readStringUntil('\n');
    if(input.startsWith("SSID:")){
      String ssid = input.substring(5);
      Serial.println("ssid");
      Serial.println(ssid);
      preferences.putString("SSID",ssid);
    }
    else if(input.startsWith("password:"))
    {
      String password = input.substring(9);
       Serial.println("password");
       Serial.println(password);
       preferences.putString("Password",password);
       ESP.restart();
      
    }
  }
  
}