#include <ESP8266WiFi.h>
#include "ESPMailer.h"
#include <Time.h>
#include <NTP.h>

const char* ssid = "virus";
const char* key = "5842@vdr";

void setup() {
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, key);
  	Serial.begin(115200);
  	Serial.println();
  	while (WiFi.status() != WL_CONNECTED) {
  		Serial.write('.');
  		delay(200);
  	}

	Serial.println("Connected to WiFi");
	ESPMailer* mail = new ESPMailer();
	/*
	 * -1 = muted
	 *  0 = only errors
	 *  1 = Client -> Server
	 *  2 = Server -> Client
	 *  3 = both
	 */
	mail->setDebugLevel(3);
	mail->Host = "smtp.gmail.org";
	mail->SMTPAuth = true;
	mail->AuthType = LOGIN;
	mail->Username = "deekshithreddy22394@gmail.com";
	mail->Password = "GMAIL5842@vdr";
	mail->setFrom("deekshithreddy22394@gmail.com","ESP8266 alert");
	mail->setTimezone(+5.5); //defaults to UTC
	mail->addAddress("deekshithreddy22394@gmail.com");
	mail->addBCC("shravanreddy27@gmail.com");
	mail->Subject = "ESP alert from home!";
	mail->isHTML(true);
	mail->Body = "<html><body>Hello <strong>ESP</strong> user!</body></html>";
	mail->AltBody = "Hello ESP user!";
	if (mail->send())
		Serial.println("Mail sent sucessfully!");
}

void loop() {
}
