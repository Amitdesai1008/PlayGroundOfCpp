INDX( 	 {�           (   8   �       U i i   <                           @�   ���c؋��M�q؋��M�q؋���c؋�                      s c . u s e r _ i n j e c t e d . 1 . e t l �              @�   ���c؋��M�q؋��M�q؋���c؋�                      S C U S E R ~ 2 . E T L                     p Z     @�   ���c؋��M�q؋��M�q؋���c؋�                      S C U S E R ~ 2 . E T L                     @�   ���c؋��M�q؋��M�q؋���c؋�                      S C  S E R ~ 2 . E T L                     @�   �:�q؋�2K2r؋�2K2r؋�:�q؋�                      S C U S E R ~ 3 . E T L                     @�   �:�q؋�2K2r؋�2K2r؋�:�q؋�                      S C U S E R ~ 3 . E T L                     a d i u s   =   r ;  
 	 }  
  
 } ;  
  
 c l a s s   S p h e r e   :   p u b l i c   C o n t a i n e r  
 {  
 p u b l i c :  
 	 f l o a t   v o l u m e ( )   {  
 	 	 f l o a t   v   =   ( ( 4   /   3 )   *   P I   *   p o w ( r a d  u s ,   3 ) ) ;  
 	 	 r e t u r n   v ;  
 	 }  
 } ;  
  
 c l a s s   C y l i n d e r   :   p u b l i c   C o n t a i n e r  
 {  
 p u b l i c :  
 	 f l o a t   v o l u m e ( )   {  
 	 	 f l o a t   v   =   P I   *   p o w ( r a d i u s ,   2 )   *   h e i g h t ;  
 	 	 r e t u r n   v ;  
 	 }  
 } ;  
  
  
 c l a s s   M y E x c e p t i o n   :   p u b l i c   e x c e p t i o n  
 {  
 p u b l i c :  
 	 M y E x c e p t i o n ( )  
 	 	 : e x c e p t i o n ( " M y E x c e p t  o n " ,   1 )    
 	 {  
  
 	 }  
  
 } ;  
  
 i n t   m a i n ( )  
 {  
 	 t r y   {  
 	 	 S p h e r e   s p h e r e ;  
 	 	 C y l i n d e r   c y l i n d e r ;  
 	 	 C o n t a i n e r   * p t r C o n t a i n e r 1   =   & s p h e r e ;  
 	 	 C o n t a i n e r   * p t r C o n t a i n e r 2   =   & c y l i n d e r ;  
 	 	 p t r C o n t a i n e r 1 - > s e t _ v o l u m e ( 3 3 . 5 3 ,   2 5 . 1 1 ,   1 . 0 ) ;  
 	 	 p t r C o n t a i n e r 2 - > s e t _ v o l u m e ( 1 3 ,   1 5 ,  1 . 0 ) ;  
 	 	 c o u t   < <   s p h e r e . v o l u m e ( )   < <   e n d l ;  
 	 	 c o u t   < <   c y l i n d e r . v o l u m e ( )   < <   e n d l ;  
 	 	 i n t *   m y a r r a y   =   n e w   i n t [ 1 0 0 0 0 ] ;  
 	 	 M y E x c e p t i o n   A ;  
 	 	 t h r o w   A   ;  
 	 	 c o u t   < <     c y l i n d e r . v o l u m e ( )   /   0 ;  
 	 }  
 	 c a t c h   ( s t d : : b a d _ a l l o c &   b a )  
 	 {  
 	 	 s t d : : c e r r   < <   " b a d _ a l l o c   c a u g h t :   "   <    b a . w h a t ( )   < <   ' \ n ' ;  
 	 }  
 	 c a t c h   ( e x c e p t i o n   E x )   {  
 	 	 c o u t   < <   E x . w h a t ( ) ;  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 