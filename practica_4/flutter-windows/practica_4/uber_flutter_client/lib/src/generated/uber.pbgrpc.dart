// This is a generated file - do not edit.
//
// Generated from uber.proto.

// @dart = 3.3

// ignore_for_file: annotate_overrides, camel_case_types, comment_references
// ignore_for_file: constant_identifier_names
// ignore_for_file: curly_braces_in_flow_control_structures
// ignore_for_file: deprecated_member_use_from_same_package, library_prefixes
// ignore_for_file: non_constant_identifier_names

import 'dart:async' as $async;
import 'dart:core' as $core;

import 'package:grpc/service_api.dart' as $grpc;
import 'package:protobuf/protobuf.dart' as $pb;

import 'google/protobuf/empty.pb.dart' as $1;
import 'uber.pb.dart' as $0;

export 'uber.pb.dart';

@$pb.GrpcServiceName('uber.UberService')
class UberServiceClient extends $grpc.Client {
  /// The hostname for this service.
  static const $core.String defaultHost = '';

  /// OAuth scopes needed for the client.
  static const $core.List<$core.String> oauthScopes = [
    '',
  ];

  UberServiceClient(super.channel, {super.options, super.interceptors});

  $grpc.ResponseFuture<$0.InfoAuto> solicitarViaje($0.Posicion request, {$grpc.CallOptions? options,}) {
    return $createUnaryCall(_$solicitarViaje, request, options: options);
  }

  $grpc.ResponseFuture<$0.ResultadoViaje> terminarViaje($0.TerminaViajeArgs request, {$grpc.CallOptions? options,}) {
    return $createUnaryCall(_$terminarViaje, request, options: options);
  }

  $grpc.ResponseFuture<$0.InfoServicio> estadoServicio($1.Empty request, {$grpc.CallOptions? options,}) {
    return $createUnaryCall(_$estadoServicio, request, options: options);
  }

    // method descriptors

  static final _$solicitarViaje = $grpc.ClientMethod<$0.Posicion, $0.InfoAuto>(
      '/uber.UberService/solicitarViaje',
      ($0.Posicion value) => value.writeToBuffer(),
      $0.InfoAuto.fromBuffer);
  static final _$terminarViaje = $grpc.ClientMethod<$0.TerminaViajeArgs, $0.ResultadoViaje>(
      '/uber.UberService/terminarViaje',
      ($0.TerminaViajeArgs value) => value.writeToBuffer(),
      $0.ResultadoViaje.fromBuffer);
  static final _$estadoServicio = $grpc.ClientMethod<$1.Empty, $0.InfoServicio>(
      '/uber.UberService/estadoServicio',
      ($1.Empty value) => value.writeToBuffer(),
      $0.InfoServicio.fromBuffer);
}

@$pb.GrpcServiceName('uber.UberService')
abstract class UberServiceBase extends $grpc.Service {
  $core.String get $name => 'uber.UberService';

  UberServiceBase() {
    $addMethod($grpc.ServiceMethod<$0.Posicion, $0.InfoAuto>(
        'solicitarViaje',
        solicitarViaje_Pre,
        false,
        false,
        ($core.List<$core.int> value) => $0.Posicion.fromBuffer(value),
        ($0.InfoAuto value) => value.writeToBuffer()));
    $addMethod($grpc.ServiceMethod<$0.TerminaViajeArgs, $0.ResultadoViaje>(
        'terminarViaje',
        terminarViaje_Pre,
        false,
        false,
        ($core.List<$core.int> value) => $0.TerminaViajeArgs.fromBuffer(value),
        ($0.ResultadoViaje value) => value.writeToBuffer()));
    $addMethod($grpc.ServiceMethod<$1.Empty, $0.InfoServicio>(
        'estadoServicio',
        estadoServicio_Pre,
        false,
        false,
        ($core.List<$core.int> value) => $1.Empty.fromBuffer(value),
        ($0.InfoServicio value) => value.writeToBuffer()));
  }

  $async.Future<$0.InfoAuto> solicitarViaje_Pre($grpc.ServiceCall $call, $async.Future<$0.Posicion> $request) async {
    return solicitarViaje($call, await $request);
  }

  $async.Future<$0.InfoAuto> solicitarViaje($grpc.ServiceCall call, $0.Posicion request);

  $async.Future<$0.ResultadoViaje> terminarViaje_Pre($grpc.ServiceCall $call, $async.Future<$0.TerminaViajeArgs> $request) async {
    return terminarViaje($call, await $request);
  }

  $async.Future<$0.ResultadoViaje> terminarViaje($grpc.ServiceCall call, $0.TerminaViajeArgs request);

  $async.Future<$0.InfoServicio> estadoServicio_Pre($grpc.ServiceCall $call, $async.Future<$1.Empty> $request) async {
    return estadoServicio($call, await $request);
  }

  $async.Future<$0.InfoServicio> estadoServicio($grpc.ServiceCall call, $1.Empty request);

}
