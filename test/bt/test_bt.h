
void openFileW()
{
    Serial.println("abriu o arq");
}

void writeOnFile(char buf[])
{
    
    for (int i = 0; i < 5; i++)
    {
        Serial.printf("write { 0x%02x }\n", buf[i]);
    }
}

void closeFile()
{
    Serial.println("fechou o arq");
}

void answer(char ans)
{
    Serial.printf("answer 0x%02x \n", ans);
}