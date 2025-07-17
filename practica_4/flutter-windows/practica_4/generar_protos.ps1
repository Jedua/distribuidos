# Ruta al plugin Dart
$protocGenDart = "$env:LOCALAPPDATA\Pub\Cache\bin\protoc-gen-dart.bat"

# Ruta destino para los archivos generados
$generatedDir = ".\uber_flutter_client\lib\src\generated"

# Crear carpeta si no existe
if (-Not (Test-Path $generatedDir)) {
    New-Item -ItemType Directory -Path $generatedDir -Force | Out-Null
    Write-Output "📁 Carpeta 'generated' creada."
} else {
    Write-Output "ℹ️ Carpeta 'generated' ya existe."
}

# Ejecutar protoc
Write-Output "⚙️ Ejecutando protoc..."
.\protoc\bin\protoc.exe `
  --plugin=protoc-gen-dart="$protocGenDart" `
  --dart_out=grpc:$generatedDir `
  -Iprotos `
  -Iprotoc\include `
  protos\uber.proto

Write-Output "✅ Archivos .dart generados correctamente en: $generatedDir"
