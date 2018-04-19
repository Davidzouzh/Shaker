#ifndef OLEDFONT__
#define OLEDFONT__ 
//����ASCII��
//ƫ����32 
//ASCII�ַ���: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//PC2LCD2002ȡģ��ʽ���ã�����+����ʽ+����+C51��ʽ
//�ܹ���2���ַ�����12*12��16*16����
//ÿ���ַ���ռ�õ��ֽ���Ϊ:(size/8+((size%8)?1:0))*(size/2),����size:���ֿ�����ʱ�ĵ����С(12/16/24...)
//12*12��12���ֽڣ�16*16: 16���ֽ�

 
//16*16 ASCII�ַ�������
const unsigned char asc2_1608[95][16]={	  
/*   (0) !(1) "(2) #(3) $(4) %(5) &(6) '(7) ((8) )(9) *(10) +(11) ,(12) -(13) .(14) /(15)
 0(16) 1(17) 2(18) 3(19) 4(20) 5(21) 6(22) 7(23) 8(24) 9(25) :(26) ;(27) <(28) =(29) >(30) ?(31)
 @(32) A(33) B(34) C(35) D(36) E(37) F(38) G(39) H(40) I(41) J(42) K(43) L(44) M(45) N(46) O(47)
 P(48) Q(49) R(50) S(51) T(52) U(53) V(54) W(55) X(56) Y(57) Z(58) [(59) \(60) ](61) ^(62) _(63)
 `(64) a(65) b(66) c(67) d(68) e(69) f(70) g(71) h(72) i(73) j(74) k(75) l(76) m(77) n(78) o(79)
 p(80) q(81) r(82) s(83) t(84) u(85) v(86) w(87) x(88) y(89) z(90) {(91) |(92) }(93) ~(94) */


 
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x30,0x00,0x00,0x00},/*"!",1*/
{0x00,0x10,0x0C,0x06,0x10,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/
{0x40,0xC0,0x78,0x40,0xC0,0x78,0x40,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x04,0x00},/*"#",3*/
{0x00,0x70,0x88,0xFC,0x08,0x30,0x00,0x00,0x00,0x18,0x20,0xFF,0x21,0x1E,0x00,0x00},/*"$",4*/
{0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00},/*"%",5*/
{0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x24,0x19,0x27,0x21,0x10},/*"&",6*/
{0x10,0x16,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00},/*"(",8*/
{0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00},/*")",9*/
{0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00},/*"*",10*/
{0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00},/*"+",11*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xB0,0x70,0x00,0x00,0x00,0x00,0x00},/*",",12*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01},/*"-",13*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00},/*".",14*/
{0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00},/*"/",15*/
{0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00},/*"0",16*/
{0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"1",17*/
{0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00},/*"2",18*/
{0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00},/*"3",19*/
{0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00},/*"4",20*/
{0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00},/*"5",21*/
{0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00},/*"6",22*/
{0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00},/*"7",23*/
{0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00},/*"8",24*/
{0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00},/*"9",25*/
{0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00},/*":",26*/
{0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00},/*";",27*/
{0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00},/*"<",28*/
{0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00},/*"=",29*/
{0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00},/*">",30*/
{0x00,0x70,0x48,0x08,0x08,0x08,0xF0,0x00,0x00,0x00,0x00,0x30,0x36,0x01,0x00,0x00},/*"?",31*/
{0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x24,0x23,0x14,0x0B,0x00},/*"@",32*/
{0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20},/*"A",33*/
{0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00},/*"B",34*/
{0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00},/*"C",35*/
{0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00},/*"D",36*/
{0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00},/*"E",37*/
{0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00},/*"F",38*/
{0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00},/*"G",39*/
{0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20},/*"H",40*/
{0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"I",41*/
{0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00},/*"J",42*/
{0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00},/*"K",43*/
{0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00},/*"L",44*/
{0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00},/*"M",45*/
{0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00},/*"N",46*/
{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00},/*"O",47*/
{0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00},/*"P",48*/
{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00},/*"Q",49*/
{0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20},/*"R",50*/
{0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00},/*"S",51*/
{0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00},/*"T",52*/
{0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00},/*"U",53*/
{0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00},/*"V",54*/
{0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00},/*"W",55*/
{0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20},/*"X",56*/
{0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00},/*"Y",57*/
{0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00},/*"Z",58*/
{0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00},/*"[",59*/
{0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00},/*"\",60*/
{0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00},/*"]",61*/
{0x00,0x00,0x04,0x02,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},/*"_",63*/
{0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20},/*"a",65*/
{0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00},/*"b",66*/
{0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00},/*"c",67*/
{0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20},/*"d",68*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00},/*"e",69*/
{0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"f",70*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00},/*"g",71*/
{0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20},/*"h",72*/
{0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"i",73*/
{0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00},/*"j",74*/
{0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00},/*"k",75*/
{0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},/*"l",76*/
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F},/*"m",77*/
{0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20},/*"n",78*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00},/*"o",79*/
{0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00},/*"p",80*/
{0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80},/*"q",81*/
{0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00},/*"r",82*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00},/*"s",83*/
{0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00},/*"t",84*/
{0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20},/*"u",85*/
{0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00},/*"v",86*/
{0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00},/*"w",87*/
{0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00},/*"x",88*/
{0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00},/*"y",89*/
{0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00},/*"z",90*/
{0x00,0x00,0x00,0x00,0x80,0x7C,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40},/*"{",91*/
{0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00},/*"|",92*/
{0x00,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00},/*"}",93*/
{0x00,0x06,0x01,0x01,0x02,0x02,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/


};  


const unsigned char asc2_2412[285][12]={	
 /** (0) !(1) "(2) #(3) $(4) %(5) &(6) '(7) ((8) )(9) *(10) +(11) ,(12) -(13) .(14) /(15)
 0(16) 1(17) 2(18) 3(19) 4(20) 5(21) 6(22) 7(23) 8(24) 9(25) :(26) ;(27) <(28) =(29) >(30) ?(31)
 @(32) A(33) B(34) C(35) D(36) E(37) F(38) G(39) H(40) I(41) J(42) K(43) L(44) M(45) N(46) O(47)
 P(48) Q(49) R(50) S(51) T(52) U(53) V(54) W(55) X(56) Y(57) Z(58) [(59) \(60) ](61) ^(62) _(63)
 `(64) a(65) b(66) c(67) d(68) e(69) f(70) g(71) h(72) i(73) j(74) k(75) l(76) m(77) n(78) o(79)
 p(80) q(81) r(82) s(83) t(84) u(85) v(86) w(87) x(88) y(89) z(90) {(91) |(92) }(93) ~(94) **/

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
	{0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x77,0x0F,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x00,0x00},/*"!",1*/
	{0x00,0x00,0x80,0x60,0x30,0x1C,0x8C,0x60,0x30,0x1C,0x0C,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/
	{0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0xF0,0x00,0x00},
	{0x00,0x83,0x83,0xFF,0x83,0x83,0x83,0x83,0xFB,0x87,0x83,0x00},
	{0x00,0x01,0x1F,0x01,0x01,0x01,0x01,0x01,0x1F,0x01,0x01,0x00},/*"#",3*/
	{0x00,0x00,0x80,0xC0,0x60,0x20,0xF8,0x20,0xE0,0xC0,0x00,0x00},
	{0x00,0x00,0x03,0x07,0x0C,0x18,0xFF,0x71,0xE1,0x81,0x00,0x00},
	{0x00,0x00,0x07,0x0F,0x12,0x10,0x7F,0x10,0x0F,0x07,0x00,0x00},/*"$",4*/
	{0xC0,0x30,0x10,0x30,0xC0,0x00,0x00,0xC0,0x30,0x00,0x00,0x00},
	{0x07,0x18,0x10,0x18,0xCF,0x38,0xC6,0x31,0x10,0x30,0xC0,0x00},
	{0x00,0x00,0x18,0x07,0x00,0x00,0x07,0x18,0x10,0x18,0x07,0x00},/*"%",5*/
	{0x00,0x00,0xE0,0xF0,0x10,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00},
	{0xC0,0xE0,0x17,0x3F,0xF8,0xC7,0x03,0x08,0xF8,0x08,0x08,0x00},
	{0x07,0x0F,0x18,0x10,0x10,0x13,0x0F,0x0E,0x19,0x10,0x10,0x0C},/*"&",6*/
	{0x00,0x00,0x8C,0x4C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x10,0x08,0x04,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xFE,0x01,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0C,0x10,0x20,0x40,0x00},/*"(",8*/
	{0x00,0x04,0x08,0x10,0x60,0x80,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x00},/*")",9*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0x00,0x00,0x00,0x00},
	{0x00,0x66,0x66,0x24,0x38,0x10,0xFF,0x18,0x3C,0x24,0x66,0x66},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00},/*"*",10*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0x10},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00},/*"+",11*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x8C,0x4C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*",",12*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*".",14*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x38,0x0C,0x00},
	{0x00,0x00,0x00,0x00,0x80,0x70,0x1C,0x03,0x00,0x00,0x00,0x00},
	{0x00,0x60,0x38,0x0E,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"/",15*/
	{0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0x60,0xC0,0x80,0x00,0x00},
	{0x00,0xFE,0xFF,0x01,0x00,0x00,0x00,0x00,0x01,0xFF,0xFE,0x00},
	{0x00,0x01,0x07,0x0E,0x18,0x10,0x10,0x18,0x0E,0x07,0x01,0x00},/*"0",16*/
	{0x00,0x00,0x40,0x40,0x40,0xC0,0xE0,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x10,0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x00,0x00},/*"1",17*/
	{0x00,0x80,0x40,0x20,0x20,0x20,0x20,0x60,0xC0,0x80,0x00,0x00},
	{0x00,0x03,0x03,0x00,0x00,0xC0,0x60,0x30,0x1F,0x07,0x00,0x00},
	{0x00,0x18,0x1C,0x12,0x11,0x10,0x10,0x10,0x10,0x1E,0x00,0x00},/*"2",18*/
	{0x00,0xC0,0xC0,0x20,0x20,0x20,0x60,0xC0,0x80,0x00,0x00,0x00},
	{0x00,0x01,0x01,0x00,0x10,0x10,0x18,0x2F,0xE7,0x80,0x00,0x00},
	{0x00,0x0E,0x0E,0x10,0x10,0x10,0x10,0x18,0x0F,0x07,0x00,0x00},/*"3",19*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xE0,0x00,0x00,0x00},
	{0x00,0xC0,0xA0,0x98,0x84,0x83,0x80,0xFF,0xFF,0x80,0x80,0x80},
	{0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x1F,0x1F,0x10,0x10,0x00},/*"4",20*/
	{0x00,0x00,0xE0,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00},
	{0x00,0x00,0x3F,0x10,0x08,0x08,0x08,0x18,0xF0,0xE0,0x00,0x00},
	{0x00,0x07,0x0B,0x10,0x10,0x10,0x10,0x1C,0x0F,0x03,0x00,0x00},/*"5",21*/
	{0x00,0x00,0x80,0xC0,0x40,0x20,0x20,0x20,0xE0,0xC0,0x00,0x00},
	{0x00,0xFC,0xFF,0x21,0x10,0x08,0x08,0x08,0x18,0xF0,0xE0,0x00},
	{0x00,0x01,0x07,0x0C,0x18,0x10,0x10,0x10,0x08,0x0F,0x03,0x00},/*"6",22*/
	{0x00,0x00,0xC0,0x60,0x20,0x20,0x20,0x20,0x20,0xE0,0x60,0x00},
	{0x00,0x00,0x01,0x00,0x00,0x00,0xE0,0x18,0x07,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00},/*"7",23*/
	{0x00,0x80,0xC0,0x60,0x20,0x20,0x20,0x20,0x60,0xC0,0x80,0x00},
	{0x00,0x83,0xCF,0x6C,0x18,0x10,0x30,0x30,0x68,0xCF,0x83,0x00},
	{0x00,0x07,0x0F,0x08,0x10,0x10,0x10,0x10,0x18,0x0F,0x07,0x00},/*"8",24*/
	{0x00,0x00,0xC0,0xC0,0x20,0x20,0x20,0x20,0xC0,0x80,0x00,0x00},
	{0x00,0x1F,0x3F,0x60,0x40,0x40,0x40,0x20,0x10,0xFF,0xFE,0x00},
	{0x00,0x00,0x0C,0x1C,0x10,0x10,0x10,0x08,0x0F,0x03,0x00,0x00},/*"9",25*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00,0x00},/*":",26*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xD8,0x38,0x00,0x00,0x00,0x00,0x00},/*";",27*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x00},
	{0x00,0x00,0x10,0x28,0x44,0x82,0x01,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00},/*"<",28*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"=",29*/
	{0x00,0x00,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x82,0x44,0x28,0x10,0x00},
	{0x00,0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00},/*">",30*/
	{0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x20,0x20,0x60,0xC0,0x80},
	{0x00,0x00,0x07,0x06,0x00,0x00,0xE0,0x10,0x18,0x08,0x0F,0x07},
	{0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00,0x00},/*"?",31*/
	{0x00,0x00,0xC0,0xE0,0x20,0x10,0x90,0x90,0xA0,0x60,0x80,0x00},
	{0x00,0xFE,0xFF,0x00,0xF8,0xFF,0x03,0xFC,0x07,0x80,0x7F,0x00},
	{0x00,0x00,0x07,0x0E,0x18,0x11,0x11,0x11,0x09,0x0C,0x02,0x00},/*"@",32*/
	{0x00,0x00,0x00,0x00,0x80,0x60,0xE0,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x80,0x78,0x47,0x40,0x41,0x5F,0xF0,0x80,0x00,0x00},
	{0x10,0x1C,0x13,0x10,0x00,0x00,0x00,0x00,0x11,0x1F,0x18,0x10},/*"A",33*/
	{0x00,0x20,0xE0,0xE0,0x20,0x20,0x20,0x60,0xC0,0xC0,0x00,0x00},
	{0x00,0x00,0xFF,0xFF,0x10,0x10,0x10,0x18,0x2F,0xE7,0x80,0x00},
	{0x00,0x10,0x1F,0x1F,0x10,0x10,0x10,0x10,0x18,0x0F,0x07,0x00},/*"B",34*/
	{0x00,0x00,0x80,0xC0,0x40,0x20,0x20,0x20,0x60,0xE0,0x80,0x00},
	{0x00,0xFC,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00},
	{0x00,0x01,0x07,0x0E,0x18,0x10,0x10,0x10,0x08,0x0C,0x03,0x00},/*"C",35*/
	{0x20,0x20,0xE0,0xE0,0x20,0x20,0x20,0x40,0xC0,0x80,0x00,0x00},
	{0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x01,0xFF,0xFE,0x00},
	{0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x08,0x0E,0x07,0x01,0x00},/*"D",36*/
	{0x20,0xE0,0xE0,0x20,0x20,0x20,0x20,0x20,0x60,0x60,0x80,0x00},
	{0x00,0xFF,0xFF,0x10,0x10,0x10,0x10,0xFC,0x00,0x00,0x01,0x00},
	{0x10,0x1F,0x1F,0x10,0x10,0x10,0x10,0x10,0x10,0x18,0x06,0x00},/*"E",37*/
	{0x20,0xE0,0xE0,0x20,0x20,0x20,0x20,0x20,0x60,0x60,0x80,0x00},
	{0x00,0xFF,0xFF,0x10,0x10,0x10,0x10,0xFC,0x00,0x00,0x01,0x00},
	{0x10,0x1F,0x1F,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"F",38*/
	{0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0x20,0x40,0x80,0x00,0x00},
	{0x00,0xFC,0xFF,0x01,0x00,0x00,0x40,0x40,0xC0,0xC3,0x40,0x40},
	{0x00,0x01,0x07,0x0E,0x18,0x10,0x10,0x10,0x0F,0x0F,0x00,0x00},/*"G",39*/
	{0x20,0xE0,0xE0,0x20,0x00,0x00,0x00,0x00,0x20,0xE0,0xE0,0x20},
	{0x00,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0x00},
	{0x10,0x1F,0x1F,0x10,0x00,0x00,0x00,0x00,0x10,0x1F,0x1F,0x10},/*"H",40*/
	{0x00,0x00,0x20,0x20,0x20,0xE0,0xE0,0x20,0x20,0x20,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x10,0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x00,0x00},/*"I",41*/
	{0x00,0x00,0x00,0x20,0x20,0x20,0xE0,0xE0,0x20,0x20,0x20,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00},
	{0x00,0x60,0xE0,0x80,0x80,0xC0,0x7F,0x3F,0x00,0x00,0x00,0x00},/*"J",42*/
	{0x20,0xE0,0xE0,0x20,0x00,0x00,0xA0,0xE0,0x60,0x20,0x00,0x00},
	{0x00,0xFF,0xFF,0x30,0x0C,0x3A,0xE1,0x80,0x00,0x00,0x00,0x00},
	{0x10,0x1F,0x1F,0x10,0x00,0x00,0x00,0x13,0x1E,0x18,0x10,0x00},/*"K",43*/
	{0x20,0xE0,0xE0,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x10,0x1F,0x1F,0x10,0x10,0x10,0x10,0x10,0x10,0x18,0x06,0x00},/*"L",44*/
	{0x20,0xE0,0xE0,0x00,0x00,0x00,0x00,0xC0,0xE0,0xE0,0x20,0x00},
	{0x00,0xFF,0x0F,0xFF,0xE0,0x80,0x7C,0x03,0xFF,0xFF,0x00,0x00},
	{0x10,0x1F,0x10,0x00,0x0F,0x07,0x00,0x10,0x1F,0x1F,0x10,0x00},/*"M",45*/
	{0x00,0x20,0xE0,0xE0,0x80,0x00,0x00,0x20,0x20,0xE0,0x20,0x20},
	{0x00,0x00,0xFF,0x01,0x07,0x1E,0x78,0xC0,0x00,0xFF,0x00,0x00},
	{0x10,0x10,0x1F,0x10,0x10,0x00,0x00,0x03,0x0F,0x1F,0x00,0x00},/*"N",46*/
	{0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0x60,0xC0,0x80,0x00,0x00},
	{0x00,0xFE,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00},
	{0x00,0x01,0x07,0x0E,0x18,0x10,0x10,0x18,0x0C,0x07,0x01,0x00},/*"O",47*/
	{0x20,0xE0,0xE0,0x20,0x20,0x20,0x20,0x20,0x40,0xC0,0x80,0x00},
	{0x00,0xFF,0xFF,0x20,0x20,0x20,0x20,0x30,0x10,0x1F,0x0F,0x00},
	{0x10,0x1F,0x1F,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"P",48*/
	{0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0x60,0xC0,0x80,0x00,0x00},
	{0x00,0xFE,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00},
	{0x00,0x01,0x07,0x0E,0x19,0x11,0x17,0x3C,0x6C,0x67,0x21,0x00},/*"Q",49*/
	{0x20,0xE0,0xE0,0x20,0x20,0x20,0x20,0x20,0x60,0xC0,0x80,0x00},
	{0x00,0xFF,0xFF,0x10,0x10,0x10,0x70,0xD0,0x08,0x0F,0x07,0x00},
	{0x10,0x1F,0x1F,0x10,0x00,0x00,0x00,0x01,0x07,0x1E,0x18,0x10},/*"R",50*/
	{0x00,0x80,0xC0,0x60,0x20,0x20,0x20,0x20,0x40,0xE0,0x00,0x00},
	{0x00,0x07,0x0F,0x1C,0x18,0x38,0x30,0x70,0xE0,0xE1,0x80,0x00},
	{0x00,0x07,0x0C,0x08,0x10,0x10,0x10,0x10,0x18,0x0F,0x07,0x00},/*"S",51*/
	{0x80,0x60,0x20,0x20,0x20,0xE0,0xE0,0x20,0x20,0x20,0x60,0x80},
	{0x01,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x01},
	{0x00,0x00,0x00,0x10,0x10,0x1F,0x1F,0x10,0x10,0x00,0x00,0x00},/*"T",52*/
	{0x00,0x20,0xE0,0xE0,0x20,0x00,0x00,0x00,0x20,0xE0,0x20,0x00},
	{0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00},
	{0x00,0x00,0x07,0x0F,0x18,0x10,0x10,0x10,0x08,0x07,0x00,0x00},/*"U",53*/
	{0x20,0x60,0xE0,0x20,0x00,0x00,0x00,0x00,0xA0,0x60,0x20,0x00},
	{0x00,0x00,0x07,0x7E,0xE0,0x00,0x80,0x78,0x07,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x07,0x1E,0x03,0x00,0x00,0x00,0x00,0x00},/*"V",54*/
	{0x20,0xE0,0x20,0x00,0x20,0x60,0xE0,0x20,0x00,0x20,0xE0,0x20},
	{0x00,0x03,0xFF,0xC0,0xC0,0x3C,0x3F,0xF0,0x80,0x7C,0x03,0x00},
	{0x00,0x00,0x00,0x1F,0x03,0x00,0x00,0x1F,0x07,0x00,0x00,0x00},/*"W",55*/
	{0x00,0x20,0x60,0xE0,0x20,0x00,0x00,0x20,0xE0,0x20,0x20,0x00},
	{0x00,0x00,0x00,0x01,0x87,0x7C,0xE8,0x86,0x01,0x00,0x00,0x00},
	{0x00,0x10,0x18,0x16,0x01,0x00,0x00,0x13,0x1E,0x18,0x10,0x00},/*"X",56*/
	{0x20,0x60,0xE0,0x20,0x00,0x00,0x00,0x00,0x20,0xA0,0x60,0x20},
	{0x00,0x00,0x01,0x0F,0x3C,0xF8,0xE0,0x18,0x06,0x01,0x00,0x00},
	{0x00,0x00,0x00,0x10,0x10,0x1F,0x1F,0x10,0x10,0x00,0x00,0x00},/*"Y",57*/
	{0x00,0x80,0xE0,0x60,0x20,0x20,0x20,0x20,0xA0,0xE0,0x20,0x00},
	{0x00,0x01,0x00,0x00,0x80,0x60,0x18,0x06,0x03,0x00,0x00,0x00},
	{0x00,0x10,0x1C,0x17,0x11,0x10,0x10,0x10,0x10,0x18,0x06,0x00},/*"Z",58*/
	{0x00,0x00,0x00,0x00,0x00,0xFC,0x04,0x04,0x04,0x04,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00},/*"[",59*/
	{0x00,0x00,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x07,0x18,0xE0,0x80,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0C,0x70,0x80,0x00},/*"\",60*/
	{0x00,0x00,0x04,0x04,0x04,0x04,0xFC,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x40,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,0x00,0x00},/*"]",61*/
	{0x00,0x00,0x00,0x08,0x04,0x02,0x02,0x04,0x08,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},/*"_",63*/
	{0x00,0x00,0x00,0x04,0x04,0x08,0x08,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x98,0x98,0x84,0x44,0x44,0x44,0xFC,0xF8,0x00,0x00},
	{0x00,0x0F,0x1F,0x19,0x10,0x10,0x10,0x08,0x0F,0x1F,0x10,0x18},/*"a",65*/
	{0x00,0x20,0xE0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xFF,0xFF,0x18,0x08,0x04,0x04,0x0C,0xF8,0xF0,0x00},
	{0x00,0x00,0x1F,0x0F,0x08,0x10,0x10,0x10,0x18,0x0F,0x03,0x00},/*"b",66*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xE0,0xF8,0x18,0x04,0x04,0x04,0x3C,0x38,0x00,0x00,0x00},
	{0x00,0x03,0x0F,0x0C,0x10,0x10,0x10,0x10,0x08,0x06,0x00,0x00},/*"c",67*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0xE0,0xF0,0x00,0x00},
	{0x00,0xE0,0xF8,0x1C,0x04,0x04,0x04,0x08,0xFF,0xFF,0x00,0x00},
	{0x00,0x03,0x0F,0x18,0x10,0x10,0x10,0x08,0x1F,0x0F,0x08,0x00},/*"d",68*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xE0,0xF8,0x88,0x84,0x84,0x84,0x8C,0xF8,0xE0,0x00},
	{0x00,0x00,0x03,0x0F,0x0C,0x10,0x10,0x10,0x10,0x08,0x04,0x00},/*"e",69*/
	{0x00,0x00,0x00,0x00,0x80,0xC0,0x60,0x20,0x20,0xE0,0xC0,0x00},
	{0x00,0x04,0x04,0x04,0xFF,0xFF,0x04,0x04,0x04,0x00,0x00,0x00},
	{0x00,0x00,0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x00,0x00,0x00},/*"f",70*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x70,0xF8,0x8C,0x04,0x0C,0xFC,0xF4,0x0C,0x0C,0x00},
	{0x00,0x70,0x7E,0xCF,0x85,0x85,0x8D,0xCD,0x78,0x78,0x00,0x00},/*"g",71*/
	{0x00,0x20,0xE0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xFF,0xFF,0x08,0x04,0x04,0x04,0xFC,0xF8,0x00,0x00},
	{0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00},/*"h",72*/
	{0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x04,0x04,0x04,0xFC,0xFE,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x10,0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x00,0x00},/*"i",73*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x04,0x04,0x04,0xFC,0xFE,0x00,0x00,0x00},
	{0x00,0x00,0xC0,0xC0,0x80,0x80,0xC0,0x7F,0x3F,0x00,0x00,0x00},/*"j",74*/
	{0x00,0x20,0xE0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0xFF,0xFF,0x80,0x40,0xE0,0x1C,0x04,0x04,0x00,0x00},
	{0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,0x13,0x1E,0x18,0x10,0x00},/*"k",75*/
	{0x00,0x00,0x20,0x20,0x20,0xE0,0xF0,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x10,0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x00,0x00},/*"l",76*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x04,0xFC,0xFC,0x08,0x04,0xFC,0xF8,0x08,0x04,0xFC,0xFC,0x00},
	{0x10,0x1F,0x1F,0x10,0x10,0x1F,0x1F,0x10,0x10,0x1F,0x1F,0x10},/*"m",77*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x04,0xFC,0xFC,0x08,0x04,0x04,0x04,0xFC,0xF8,0x00,0x00},
	{0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00},/*"n",78*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xE0,0xF0,0x18,0x0C,0x04,0x04,0x0C,0x18,0xF0,0xE0,0x00},
	{0x00,0x03,0x0F,0x0C,0x10,0x10,0x10,0x10,0x0C,0x0F,0x03,0x00},/*"o",79*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x04,0xFC,0xFC,0x08,0x04,0x04,0x04,0x0C,0xF8,0xF0,0x00},
	{0x00,0x80,0xFF,0xFF,0x88,0x90,0x10,0x10,0x1C,0x0F,0x03,0x00},/*"p",80*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0xE0,0xF8,0x1C,0x04,0x04,0x04,0x08,0xF8,0xFC,0x00,0x00},
	{0x00,0x03,0x0F,0x18,0x10,0x10,0x90,0x88,0xFF,0xFF,0x80,0x00},/*"q",81*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x04,0x04,0x04,0xFC,0xFC,0x10,0x08,0x04,0x04,0x1C,0x18,0x00},
	{0x10,0x10,0x10,0x1F,0x1F,0x10,0x10,0x10,0x00,0x00,0x00,0x00},/*"r",82*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x38,0x78,0xCC,0xC4,0x84,0x84,0x0C,0x3C,0x00,0x00},
	{0x00,0x00,0x1E,0x18,0x10,0x10,0x11,0x19,0x1F,0x0F,0x00,0x00},/*"s",83*/
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x04,0x04,0x04,0xFF,0xFF,0x04,0x04,0x04,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x0F,0x1F,0x10,0x10,0x10,0x0C,0x00,0x00},/*"t",84*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x04,0xFC,0xFE,0x00,0x00,0x00,0x04,0xFC,0xFE,0x00,0x00},
	{0x00,0x00,0x0F,0x1F,0x18,0x10,0x10,0x08,0x1F,0x0F,0x08,0x00},/*"u",85*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x04,0x0C,0x7C,0xC4,0x00,0x00,0x80,0x74,0x0C,0x04,0x00},
	{0x00,0x00,0x00,0x00,0x03,0x1F,0x0C,0x03,0x00,0x00,0x00,0x00},/*"v",86*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x04,0x1C,0xF4,0x80,0x04,0xEC,0xFC,0x84,0x00,0xE4,0x1C,0x04},
	{0x00,0x00,0x01,0x1F,0x0F,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00},/*"w",87*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x04,0x0C,0x3C,0xE4,0xC0,0x24,0x1C,0x04,0x04,0x00},
	{0x00,0x10,0x10,0x1C,0x12,0x01,0x01,0x13,0x1C,0x18,0x10,0x00},/*"x",88*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x04,0x04,0x3C,0xC4,0x00,0x00,0xC4,0x3C,0x04,0x04,0x00},
	{0x00,0x00,0xC0,0x80,0x81,0x7F,0x0E,0x01,0x00,0x00,0x00,0x00},/*"y",89*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x3C,0x04,0x04,0xC4,0x74,0x1C,0x0C,0x00,0x00,0x00},
	{0x00,0x00,0x18,0x1E,0x13,0x11,0x10,0x10,0x18,0x0E,0x00,0x00},/*"z",90*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x04,0x04,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x10,0x28,0xC7,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,0x00,0x00},/*"{",91*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},/*"|",92*/
	{0x00,0x00,0x04,0x04,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0xC7,0x28,0x10,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"}",93*/
	{0x00,0x0C,0x02,0x02,0x02,0x04,0x08,0x18,0x10,0x10,0x0C,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/
};
	
	
#endif
