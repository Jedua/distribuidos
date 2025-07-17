
flutter emulators --launch flutter_emulator 


.\protoc\bin\protoc.exe `
  --plugin=protoc-gen-dart="C:\Users\pepel\AppData\Local\Pub\Cache\bin\protoc-gen-dart.bat" `
  --dart_out=grpc:uber_flutter_client\lib\src\generated `
  -Iprotos `
  -Iprotoc\include `
  protos\uber.proto


Get-Process | Where-Object { $_.Name -like "dart*" -or $_.Name -like "flutter*" } | Stop-Process -Force
Remove-Item -Recurse -Force .\build
Test-Path .\build
flutter run -d chrome

flutter emulators
flutter emulators --create
flutter devices
emulator-5554 • emulator-5554 • android-x86 • Android 12 (API 31)
flutter run -d emulator-5554

flutter emulators --launch Medium_Phone_API_36.0


Stop-Process -Name dart -Force -ErrorAction SilentlyContinue
Stop-Process -Name gradle -Force -ErrorAction SilentlyContinue
Remove-Item -Recurse -Force .\build\
flutter clean
flutter pub get
flutter run -d emulator-5554

Stop-Process -Name adb -Force -ErrorAction SilentlyContinue
Stop-Process -Name java -Force -ErrorAction SilentlyContinue
Stop-Process -Name gradle -Force -ErrorAction SilentlyContinue
Stop-Process -Name flutter -Force -ErrorAction SilentlyContinue

Stop-Process -Name dart -Force -ErrorAction SilentlyContinue
Stop-Process -Name gradle -Force -ErrorAction SilentlyContinue
Remove-Item -Recurse -Force .\build\
flutter clean
flutter pub get
flutter run -d emulator-5558
flutter run -d emulator-5556