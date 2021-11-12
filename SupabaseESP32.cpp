#include "SupabaseESP32.h"

// #if ESP32
HTTPClient http;
// #endif

String supabase_url;
String supabase_key;
String supabase_bearer;
String supabase_table;

SUPABASE::SUPABASE(String url, String key, String Bearer, String tableName)
{
    supabase_table = tableName;
    supabase_url = url + "/" + supabase_table;
    supabase_key = key;
    supabase_bearer = Bearer;
}

SUPABASE::~SUPABASE() {}

void SUPABASE::begin()
{
    // String Supabase_url_server = supabase_url+"/"+supabase_table;
    Serial.println(supabase_url);
    http.begin(supabase_url.c_str());
    http.addHeader("apikey", supabase_key);
    http.addHeader("Authorization", supabase_bearer);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Prefer", "return=representation");
}

int SUPABASE::UPDATE(String supabase_data)
{
    http.begin(supabase_url.c_str());
    http.addHeader("apikey", supabase_key);
    http.addHeader("Authorization", supabase_bearer);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Prefer", "resolution=merge-duplicates");
    int httpResponseCode = http.POST(supabase_data);
    String payload = http.getString();
    Serial.println(payload);
    http.end();
    return httpResponseCode;
}
int SUPABASE::INSERT(String supabase_data)
{

    int httpResponseCode = http.POST(supabase_data);
    String payload = http.getString();
    http.end();
    return httpResponseCode;
}
