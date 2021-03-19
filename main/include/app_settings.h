#ifndef APP_SETTINGS_H_
#define APP_SETTINGS_H_

#include "idf_version.h"

#if defined(__USE_LWIP_IP_4_ADDR)
#include <lwip/ip4_addr.h>
#else
#include <esp_netif.h>
#endif

//lengths in characters WO null term
#define LEN_WIFI_SSID     31
#define LEN_WIFI_PASSWORD 63
#define LEN_HOSTNAME      32
<<<<<<< HEAD
#define LEN_HTTP_USER	  16
#define LEN_HTTP_PASSWORD 16
=======
#define LEN_HTTP_USER	  16		//incl string termination /0 => 15 effective
#define LEN_HTTP_PASSWORD 16		//incl string termination /0 => 15 effective
>>>>>>> 3db4a7ed873711ce49d4631463eecbc978dc902e
#ifdef CONFIG_MDNS_ENABLED
#define LEN_MDNS_INSTANCE 32
#endif
#ifdef CONFIG_SNTP_ENABLED
#define LEN_NTP_SERVER    32
#define LEN_TIMEZONE      32
#endif

#ifdef CONFIG_DEF_HTTP_AUTH_ENABLED
#define CONFIG_DEF_HTTP_AUTH_ENABLED true
#else
#define CONFIG_DEF_HTTP_AUTH_ENABLED false
#endif

struct app_settings_t {
  int size;
  char wifi_ssid[LEN_WIFI_SSID + 1];
  char wifi_password[LEN_WIFI_PASSWORD + 1];
  char hostname[LEN_HOSTNAME + 1];
  #ifdef CONFIG_MDNS_ENABLED
  char mdns_instance[LEN_MDNS_INSTANCE + 1];
  #endif
  #ifdef CONFIG_SNTP_ENABLED
  char ntp_server[LEN_NTP_SERVER + 1];
  char timezone[LEN_TIMEZONE + 1];
  #endif
  bool dhcp;
  uint8_t fps;
  bool http_auth;
  char http_user[LEN_HTTP_USER + 1];
  char http_password[LEN_HTTP_PASSWORD + 1];
#if defined(__USE_LWIP_IP_4_ADDR)
  ip4_addr_t ip;
  ip4_addr_t netmask;
  ip4_addr_t gateway;
  ip4_addr_t dns1;
  ip4_addr_t dns2;
<<<<<<< HEAD
#else
  esp_ip4_addr_t ip;
  esp_ip4_addr_t netmask;
  esp_ip4_addr_t gateway;
  esp_ip4_addr_t dns1;
  esp_ip4_addr_t dns2;
#endif
=======
  uint8_t fps;
  bool http_auth;
  char http_user[LEN_HTTP_USER + 1];
  char http_password[LEN_HTTP_PASSWORD + 1];
>>>>>>> 3db4a7ed873711ce49d4631463eecbc978dc902e
} settings;

void app_settings_save();
void app_settings_reset();
void app_settings_startup();
void app_settings_shutdown();

#endif
