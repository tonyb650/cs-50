import qrcode

img = qrcode.make("http://wedding-ws.pro")

img.save("qr.png", "PNG")
