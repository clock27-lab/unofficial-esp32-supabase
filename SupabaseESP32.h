// #ifndef LED13_H
// #define LED13_H
#include <WiFi.h>
#include <HTTPClient.h>
class SUPABASE
{
public:
    SUPABASE(String url, String key, String Bearer, String tableName);
    ~SUPABASE();
    void begin();
    int UPDATE(String supabase_data);
    int INSERT(String supabase_data);
    // void initSupabase();
};