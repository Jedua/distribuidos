// This is a generated file - do not edit.
//
// Generated from uber.proto.

// @dart = 3.3

// ignore_for_file: annotate_overrides, camel_case_types, comment_references
// ignore_for_file: constant_identifier_names
// ignore_for_file: curly_braces_in_flow_control_structures
// ignore_for_file: deprecated_member_use_from_same_package, library_prefixes
// ignore_for_file: non_constant_identifier_names, unused_import

import 'dart:convert' as $convert;
import 'dart:core' as $core;
import 'dart:typed_data' as $typed_data;

@$core.Deprecated('Use posicionDescriptor instead')
const Posicion$json = {
  '1': 'Posicion',
  '2': [
    {'1': 'latitud', '3': 1, '4': 1, '5': 1, '10': 'latitud'},
    {'1': 'longitud', '3': 2, '4': 1, '5': 1, '10': 'longitud'},
  ],
};

/// Descriptor for `Posicion`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List posicionDescriptor = $convert.base64Decode(
    'CghQb3NpY2lvbhIYCgdsYXRpdHVkGAEgASgBUgdsYXRpdHVkEhoKCGxvbmdpdHVkGAIgASgBUg'
    'hsb25naXR1ZA==');

@$core.Deprecated('Use infoAutoDescriptor instead')
const InfoAuto$json = {
  '1': 'InfoAuto',
  '2': [
    {'1': 'id', '3': 1, '4': 1, '5': 5, '10': 'id'},
    {'1': 'posicion', '3': 2, '4': 1, '5': 11, '6': '.uber.Posicion', '10': 'posicion'},
    {'1': 'distancia', '3': 3, '4': 1, '5': 1, '10': 'distancia'},
    {'1': 'precio', '3': 4, '4': 1, '5': 1, '10': 'precio'},
  ],
};

/// Descriptor for `InfoAuto`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List infoAutoDescriptor = $convert.base64Decode(
    'CghJbmZvQXV0bxIOCgJpZBgBIAEoBVICaWQSKgoIcG9zaWNpb24YAiABKAsyDi51YmVyLlBvc2'
    'ljaW9uUghwb3NpY2lvbhIcCglkaXN0YW5jaWEYAyABKAFSCWRpc3RhbmNpYRIWCgZwcmVjaW8Y'
    'BCABKAFSBnByZWNpbw==');

@$core.Deprecated('Use terminaViajeArgsDescriptor instead')
const TerminaViajeArgs$json = {
  '1': 'TerminaViajeArgs',
  '2': [
    {'1': 'id_auto', '3': 1, '4': 1, '5': 5, '10': 'idAuto'},
    {'1': 'posicion', '3': 2, '4': 1, '5': 11, '6': '.uber.Posicion', '10': 'posicion'},
  ],
};

/// Descriptor for `TerminaViajeArgs`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List terminaViajeArgsDescriptor = $convert.base64Decode(
    'ChBUZXJtaW5hVmlhamVBcmdzEhcKB2lkX2F1dG8YASABKAVSBmlkQXV0bxIqCghwb3NpY2lvbh'
    'gCIAEoCzIOLnViZXIuUG9zaWNpb25SCHBvc2ljaW9u');

@$core.Deprecated('Use infoServicioDescriptor instead')
const InfoServicio$json = {
  '1': 'InfoServicio',
  '2': [
    {'1': 'total_viajes', '3': 1, '4': 1, '5': 5, '10': 'totalViajes'},
    {'1': 'autos', '3': 2, '4': 3, '5': 11, '6': '.uber.Auto', '10': 'autos'},
  ],
};

/// Descriptor for `InfoServicio`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List infoServicioDescriptor = $convert.base64Decode(
    'CgxJbmZvU2VydmljaW8SIQoMdG90YWxfdmlhamVzGAEgASgFUgt0b3RhbFZpYWplcxIgCgVhdX'
    'RvcxgCIAMoCzIKLnViZXIuQXV0b1IFYXV0b3M=');

@$core.Deprecated('Use autoDescriptor instead')
const Auto$json = {
  '1': 'Auto',
  '2': [
    {'1': 'id', '3': 1, '4': 1, '5': 5, '10': 'id'},
    {'1': 'posicion', '3': 2, '4': 1, '5': 11, '6': '.uber.Posicion', '10': 'posicion'},
    {'1': 'disponible', '3': 3, '4': 1, '5': 8, '10': 'disponible'},
  ],
};

/// Descriptor for `Auto`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List autoDescriptor = $convert.base64Decode(
    'CgRBdXRvEg4KAmlkGAEgASgFUgJpZBIqCghwb3NpY2lvbhgCIAEoCzIOLnViZXIuUG9zaWNpb2'
    '5SCHBvc2ljaW9uEh4KCmRpc3BvbmlibGUYAyABKAhSCmRpc3BvbmlibGU=');

@$core.Deprecated('Use resultadoViajeDescriptor instead')
const ResultadoViaje$json = {
  '1': 'ResultadoViaje',
  '2': [
    {'1': 'precio', '3': 1, '4': 1, '5': 1, '10': 'precio'},
  ],
};

/// Descriptor for `ResultadoViaje`. Decode as a `google.protobuf.DescriptorProto`.
final $typed_data.Uint8List resultadoViajeDescriptor = $convert.base64Decode(
    'Cg5SZXN1bHRhZG9WaWFqZRIWCgZwcmVjaW8YASABKAFSBnByZWNpbw==');

