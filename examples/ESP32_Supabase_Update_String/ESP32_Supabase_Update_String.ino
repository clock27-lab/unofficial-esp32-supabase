#include <SupabaseESP32.h>
#include "supabase_secret.h"

SUPABASE supabaseClient(supabaseUrl, supabaseApiKey, supabaseBearer, tableRealtime);

const char *ssid = "Fahmi's House"; // ganti dengan SSID Wifi Sampeyan
const char *password = "Nganjuk27"; // ganti dengan Password Wifi Sampeyan

void updateData()
{
    Serial.println("Insert to Supabase");
    String dataSupabase = "{\"id\":\"1\",\"data\":\"fahmi update maulana\"}";
    int codeRespon = supabaseClient.UPDATE(dataSupabase);
    Serial.println(codeRespon);
}

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println(".");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    // put your setup code here, to run once:
    supabaseClient.begin();

    delay(2000);
    updateData();
}

void loop()
{
    // put your main code here, to run repeatedly:
}