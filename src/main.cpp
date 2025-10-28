// <<<<<<< ********************************************************* >>>>>>>>>

// Youtube >>> H.M.Ç >>> https://www.youtube.com/@h.m.c3847
// Linkedin >>> https://www.linkedin.com/in/hasan-mesut-%C3%A7etin-975744286/

    /*
    Açıklama: Renk Paletleri
    0xFFFFFF → Beyaz
    0x000000 → Siyah
    0xFF0000 → Kırmızı
    0x00FF00 → Yeşil
    0x0000FF → Mavi
    0xFFB347 → Turuncu
  */

#include <lvgl.h>
#include <TFT_eSPI.h> // TFT ekran için

#define TFT_HOR_RES 320 
#define TFT_VER_RES 240 
#define TFT_ROTATION LV_DISPLAY_ROTATION_0



// LVGL'nin çizeceği alan için buffer  
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8)) 
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Arduino'nun millis() fonksiyonu LVGL'nin zaman kaynağı olacak 
static uint32_t my_tick(void)
{ 
   return millis();
}

void setup() 
{ 
   lv_init();
   lv_tick_set_cb(my_tick); // Zamanlayıcı olarak millis() kullan 

   // --------------------------------------------------------------------------------------------

   // --- EKRAN BAĞLANTISI --- 
   lv_display_t *disp; 
   disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf)); 
   lv_display_set_rotation(disp, TFT_ROTATION);  

   // --- ARKA PLAN RENGİ AYARLA --- 
   lv_obj_t *scr = lv_screen_active(); 
   lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), 0); 
   
   // --- GÖRÜNMEYİ SINIRLAYAN ŞEFFAF KAP (PENCERE) ---
   lv_obj_t *window = lv_obj_create(scr);
   lv_obj_set_size(window, 110, 30); // Yazının görüneceği alan boyutu
   lv_obj_align(window, LV_ALIGN_BOTTOM_RIGHT, -10, -10); // Sağ alt köşe
   
   // Şeffaf yap ama kesme özelliğini aktif et
   lv_obj_set_style_bg_opa(window, LV_OPA_TRANSP, 0); // Şeffaf arkaplan
   lv_obj_set_style_border_opa(window, LV_OPA_TRANSP, 0); // Şeffaf kenarlık
   lv_obj_set_style_pad_all(window, 0, 0); // Padding yok
   lv_obj_add_flag(window, LV_OBJ_FLAG_OVERFLOW_VISIBLE); // Taşmayı gizle (ÖNEMLI!)
   lv_obj_clear_flag(window, LV_OBJ_FLAG_SCROLLABLE); // Kaydırma yok
   
   // --- DAİRESEL KAYAN YAZI ---
   lv_obj_t *scrolling_label = lv_label_create(window);
   lv_label_set_long_mode(scrolling_label, LV_LABEL_LONG_SCROLL_CIRCULAR); // Dairesel kayma
   lv_label_set_text(scrolling_label, "H.M.C       ");
   lv_obj_set_style_text_color(scrolling_label, lv_color_hex(0xFFFFFF), 0); // Beyaz yazı
   lv_obj_set_style_text_font(scrolling_label, &lv_font_montserrat_36, 0);
   
   // Yazıyı pencere genişliğine ayarla
   lv_obj_set_width(scrolling_label, 110); // Pencere boyutu kadar
   lv_obj_align(scrolling_label, LV_ALIGN_LEFT_MID, 0, 0); // Sola hizala
   lv_obj_set_style_anim_time(scrolling_label, 7000, LV_PART_MAIN); // 7 saniyede bir tur Animasyon hızını ayarla (ms cinsinden)

   //------------2. Label Oluşturma Sağ Alt ----------------------------------------------

   // --- GÖRÜNMEYİ SINIRLAYAN ŞEFFAF KAP (PENCERE) ---
   lv_obj_t *window2 = lv_obj_create(scr);
   lv_obj_set_size(window2, 70, 30); // Yazının görüneceği alan boyutu
   lv_obj_align(window2, LV_ALIGN_BOTTOM_LEFT, -10, -10); // Sol alt köşe

   // Şeffaf yap ama kesme özelliğini aktif et
   lv_obj_set_style_bg_opa(window2, LV_OPA_TRANSP, 0); // Şeffaf arkaplan
   lv_obj_set_style_border_opa(window2, LV_OPA_TRANSP, 0); // Şeffaf kenarlık
   lv_obj_set_style_pad_all(window2, 0, 0); // Padding yok
   lv_obj_add_flag(window2, LV_OBJ_FLAG_OVERFLOW_VISIBLE); // Taşmayı gizle (ÖNEMLI!)
   lv_obj_clear_flag(window2, LV_OBJ_FLAG_SCROLLABLE); // Kaydırma yok

   // --- DAİRESEL KAYAN YAZI ---
   lv_obj_t *scrolling_label2 = lv_label_create(window2);
   lv_label_set_long_mode(scrolling_label2, LV_LABEL_LONG_SCROLL_CIRCULAR); // Dairesel kayma
   lv_label_set_text(scrolling_label2, "H.M.C       ");
   lv_obj_set_style_text_color(scrolling_label2, lv_color_hex(0x00FF00), 0); // Beyaz yazı
   lv_obj_set_style_text_font(scrolling_label2, &lv_font_montserrat_22, 0);

   // Yazıyı pencere genişliğine ayarla
   lv_obj_set_width(scrolling_label2, 70); // Pencere boyutu kadar
   lv_obj_align(scrolling_label2, LV_ALIGN_LEFT_MID, 0, 0); // Sola hizala
   lv_obj_set_style_anim_time(scrolling_label2, 7000, LV_PART_MAIN); // 7 saniyede bir tur Animasyon hızını ayarla (ms cinsinden)

   // >>>>>------------3. Label Oluşturma Sağ Alt----------------------------------------<<<<<

   // --- GÖRÜNMEYİ SINIRLAYAN ŞEFFAF KAP (PENCERE) ---
   lv_obj_t *window3 = lv_obj_create(scr);
   lv_obj_set_size(window3, 60, 30); // Yazının görüneceği alan boyutu
   lv_obj_align(window3, LV_ALIGN_TOP_RIGHT, -10, 10); // Sol üst köşe

   // Şeffaf yap ama kesme özelliğini aktif et
   lv_obj_set_style_bg_opa(window3, LV_OPA_TRANSP, 0); // Şeffaf arkaplan
   lv_obj_set_style_border_opa(window3, LV_OPA_TRANSP, 0); // Şeffaf kenarlık
   lv_obj_set_style_pad_all(window3, 0, 0); // Padding yok
   lv_obj_add_flag(window3, LV_OBJ_FLAG_OVERFLOW_VISIBLE); // Taşmayı gizle (ÖNEMLI!)
   lv_obj_clear_flag(window3, LV_OBJ_FLAG_SCROLLABLE); // Kaydırma yok

   // --- DAİRESEL KAYAN YAZI ---
   lv_obj_t *scrolling_label3 = lv_label_create(window3);
   lv_label_set_long_mode(scrolling_label3, LV_LABEL_LONG_SCROLL_CIRCULAR); // Dairesel kayma
   lv_label_set_text(scrolling_label3, "H.M.C       ");
   lv_obj_set_style_text_color(scrolling_label3, lv_color_hex(0xFF0000), 0); // Kırmızı
   lv_obj_set_style_text_font(scrolling_label3, &lv_font_montserrat_18, 0);

   // Yazıyı pencere genişliğine ayarla
   lv_obj_set_width(scrolling_label3, 60); // Pencere boyutu kadar
   lv_obj_align(scrolling_label3, LV_ALIGN_LEFT_MID, 0, 0); // Sola hizala
   lv_obj_set_style_anim_time(scrolling_label3, 7000, LV_PART_MAIN); // 7 saniyede bir tur Animasyon hızını ayarla (ms cinsinden)


   // >>>>>------------4. Label Oluşturma Sağ Alt----------------------------------------<<<<<

   // --- GÖRÜNMEYİ SINIRLAYAN ŞEFFAF KAP (PENCERE) ---
   lv_obj_t *window4 = lv_obj_create(scr);
   lv_obj_set_size(window4, 60, 30); // Yazının görüneceği alan boyutu
   lv_obj_align(window4, LV_ALIGN_TOP_LEFT, -10, 10); // Sol üst köşe

   // Şeffaf yap ama kesme özelliğini aktif et
   lv_obj_set_style_bg_opa(window4, LV_OPA_TRANSP, 0); // Şeffaf arkaplan
   lv_obj_set_style_border_opa(window4, LV_OPA_TRANSP, 0); // Şeffaf kenarlık
   lv_obj_set_style_pad_all(window4, 0, 0); // Padding yok
   lv_obj_add_flag(window4, LV_OBJ_FLAG_OVERFLOW_VISIBLE); // Taşmayı gizle (ÖNEMLI!)
   lv_obj_clear_flag(window4, LV_OBJ_FLAG_SCROLLABLE); // Kaydırma yok

   // --- DAİRESEL KAYAN YAZI ---
   lv_obj_t *scrolling_label4 = lv_label_create(window4);
   lv_label_set_long_mode(scrolling_label4, LV_LABEL_LONG_SCROLL_CIRCULAR); // Dairesel kayma
   lv_label_set_text(scrolling_label4, "H.M.C       ");
   lv_obj_set_style_text_color(scrolling_label4, lv_color_hex(0xFFFFFF), 0); // Beyaz yazı
   lv_obj_set_style_text_font(scrolling_label4, &lv_font_montserrat_14, 0);

   // Yazıyı pencere genişliğine ayarla
   lv_obj_set_width(scrolling_label4, 60); // Pencere boyutu kadar
   lv_obj_align(scrolling_label4, LV_ALIGN_LEFT_MID, 0, 0); // Sola hizala
   lv_obj_set_style_anim_time(scrolling_label4, 7000, LV_PART_MAIN); // 7 saniyede bir tur Animasyon hızını ayarla (ms cinsinden)


   // >>>>>------------5. Label Oluşturma Tam Orta----------------------------------------<<<<<

   // --- GÖRÜNMEYİ SINIRLAYAN ŞEFFAF KAP (PENCERE) ---
   lv_obj_t *window5 = lv_obj_create(scr);
   lv_obj_set_size(window5, 110, 50); // Yazının görüneceği alan boyutu
   lv_obj_align(window5, LV_ALIGN_CENTER, 0, 0); // Tam Orta

   // Şeffaf yap ama kesme özelliğini aktif et
   lv_obj_set_style_bg_opa(window5, LV_OPA_TRANSP, 0); // Şeffaf arkaplan
   lv_obj_set_style_border_opa(window5, LV_OPA_TRANSP, 0); // Şeffaf kenarlık
   lv_obj_set_style_pad_all(window5, 0, 0); // Padding yok
   lv_obj_add_flag(window5, LV_OBJ_FLAG_OVERFLOW_VISIBLE); // Taşmayı gizle (ÖNEMLI!)
   lv_obj_clear_flag(window5, LV_OBJ_FLAG_SCROLLABLE); // Kaydırma yok

   // --- DAİRESEL KAYAN YAZI ---
   lv_obj_t *scrolling_label5 = lv_label_create(window5);
   lv_label_set_long_mode(scrolling_label5, LV_LABEL_LONG_SCROLL_CIRCULAR); // Dairesel kayma
   lv_label_set_text(scrolling_label5, "H.M.C       ");
   lv_obj_set_style_text_color(scrolling_label5, lv_color_hex(0xFFB347), 0); // Beyaz yazı
   lv_obj_set_style_text_font(scrolling_label5, &lv_font_montserrat_48, 0);

   // Yazıyı pencere genişliğine ayarla
   lv_obj_set_width(scrolling_label5, 110); // Pencere boyutu kadar
   lv_obj_align(scrolling_label5, LV_ALIGN_LEFT_MID, 0, 0); // Sola hizala
   lv_obj_set_style_anim_time(scrolling_label5, 7000, LV_PART_MAIN); // 7 saniyede bir tur Animasyon hızını ayarla (ms cinsinden)

}

void loop() 
{ 
   lv_timer_handler(); // LVGL görevlerini çalıştır 
   delay(5); 
}
