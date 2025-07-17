// This is a generated file - do not edit.
//
// Generated from uber.proto.

// @dart = 3.3

// ignore_for_file: annotate_overrides, camel_case_types, comment_references
// ignore_for_file: constant_identifier_names
// ignore_for_file: curly_braces_in_flow_control_structures
// ignore_for_file: deprecated_member_use_from_same_package, library_prefixes
// ignore_for_file: non_constant_identifier_names

import 'dart:core' as $core;

import 'package:protobuf/protobuf.dart' as $pb;

export 'package:protobuf/protobuf.dart' show GeneratedMessageGenericExtensions;

class Posicion extends $pb.GeneratedMessage {
  factory Posicion({
    $core.double? latitud,
    $core.double? longitud,
  }) {
    final result = create();
    if (latitud != null) result.latitud = latitud;
    if (longitud != null) result.longitud = longitud;
    return result;
  }

  Posicion._();

  factory Posicion.fromBuffer($core.List<$core.int> data, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromBuffer(data, registry);
  factory Posicion.fromJson($core.String json, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromJson(json, registry);

  static final $pb.BuilderInfo _i = $pb.BuilderInfo(_omitMessageNames ? '' : 'Posicion', package: const $pb.PackageName(_omitMessageNames ? '' : 'uber'), createEmptyInstance: create)
    ..a<$core.double>(1, _omitFieldNames ? '' : 'latitud', $pb.PbFieldType.OD)
    ..a<$core.double>(2, _omitFieldNames ? '' : 'longitud', $pb.PbFieldType.OD)
    ..hasRequiredFields = false
  ;

  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  Posicion clone() => Posicion()..mergeFromMessage(this);
  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  Posicion copyWith(void Function(Posicion) updates) => super.copyWith((message) => updates(message as Posicion)) as Posicion;

  @$core.override
  $pb.BuilderInfo get info_ => _i;

  @$core.pragma('dart2js:noInline')
  static Posicion create() => Posicion._();
  @$core.override
  Posicion createEmptyInstance() => create();
  static $pb.PbList<Posicion> createRepeated() => $pb.PbList<Posicion>();
  @$core.pragma('dart2js:noInline')
  static Posicion getDefault() => _defaultInstance ??= $pb.GeneratedMessage.$_defaultFor<Posicion>(create);
  static Posicion? _defaultInstance;

  @$pb.TagNumber(1)
  $core.double get latitud => $_getN(0);
  @$pb.TagNumber(1)
  set latitud($core.double value) => $_setDouble(0, value);
  @$pb.TagNumber(1)
  $core.bool hasLatitud() => $_has(0);
  @$pb.TagNumber(1)
  void clearLatitud() => $_clearField(1);

  @$pb.TagNumber(2)
  $core.double get longitud => $_getN(1);
  @$pb.TagNumber(2)
  set longitud($core.double value) => $_setDouble(1, value);
  @$pb.TagNumber(2)
  $core.bool hasLongitud() => $_has(1);
  @$pb.TagNumber(2)
  void clearLongitud() => $_clearField(2);
}

class InfoAuto extends $pb.GeneratedMessage {
  factory InfoAuto({
    $core.int? id,
    Posicion? posicion,
    $core.double? distancia,
    $core.double? precio,
  }) {
    final result = create();
    if (id != null) result.id = id;
    if (posicion != null) result.posicion = posicion;
    if (distancia != null) result.distancia = distancia;
    if (precio != null) result.precio = precio;
    return result;
  }

  InfoAuto._();

  factory InfoAuto.fromBuffer($core.List<$core.int> data, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromBuffer(data, registry);
  factory InfoAuto.fromJson($core.String json, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromJson(json, registry);

  static final $pb.BuilderInfo _i = $pb.BuilderInfo(_omitMessageNames ? '' : 'InfoAuto', package: const $pb.PackageName(_omitMessageNames ? '' : 'uber'), createEmptyInstance: create)
    ..a<$core.int>(1, _omitFieldNames ? '' : 'id', $pb.PbFieldType.O3)
    ..aOM<Posicion>(2, _omitFieldNames ? '' : 'posicion', subBuilder: Posicion.create)
    ..a<$core.double>(3, _omitFieldNames ? '' : 'distancia', $pb.PbFieldType.OD)
    ..a<$core.double>(4, _omitFieldNames ? '' : 'precio', $pb.PbFieldType.OD)
    ..hasRequiredFields = false
  ;

  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  InfoAuto clone() => InfoAuto()..mergeFromMessage(this);
  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  InfoAuto copyWith(void Function(InfoAuto) updates) => super.copyWith((message) => updates(message as InfoAuto)) as InfoAuto;

  @$core.override
  $pb.BuilderInfo get info_ => _i;

  @$core.pragma('dart2js:noInline')
  static InfoAuto create() => InfoAuto._();
  @$core.override
  InfoAuto createEmptyInstance() => create();
  static $pb.PbList<InfoAuto> createRepeated() => $pb.PbList<InfoAuto>();
  @$core.pragma('dart2js:noInline')
  static InfoAuto getDefault() => _defaultInstance ??= $pb.GeneratedMessage.$_defaultFor<InfoAuto>(create);
  static InfoAuto? _defaultInstance;

  @$pb.TagNumber(1)
  $core.int get id => $_getIZ(0);
  @$pb.TagNumber(1)
  set id($core.int value) => $_setSignedInt32(0, value);
  @$pb.TagNumber(1)
  $core.bool hasId() => $_has(0);
  @$pb.TagNumber(1)
  void clearId() => $_clearField(1);

  @$pb.TagNumber(2)
  Posicion get posicion => $_getN(1);
  @$pb.TagNumber(2)
  set posicion(Posicion value) => $_setField(2, value);
  @$pb.TagNumber(2)
  $core.bool hasPosicion() => $_has(1);
  @$pb.TagNumber(2)
  void clearPosicion() => $_clearField(2);
  @$pb.TagNumber(2)
  Posicion ensurePosicion() => $_ensure(1);

  @$pb.TagNumber(3)
  $core.double get distancia => $_getN(2);
  @$pb.TagNumber(3)
  set distancia($core.double value) => $_setDouble(2, value);
  @$pb.TagNumber(3)
  $core.bool hasDistancia() => $_has(2);
  @$pb.TagNumber(3)
  void clearDistancia() => $_clearField(3);

  @$pb.TagNumber(4)
  $core.double get precio => $_getN(3);
  @$pb.TagNumber(4)
  set precio($core.double value) => $_setDouble(3, value);
  @$pb.TagNumber(4)
  $core.bool hasPrecio() => $_has(3);
  @$pb.TagNumber(4)
  void clearPrecio() => $_clearField(4);
}

class TerminaViajeArgs extends $pb.GeneratedMessage {
  factory TerminaViajeArgs({
    $core.int? idAuto,
    Posicion? posicion,
  }) {
    final result = create();
    if (idAuto != null) result.idAuto = idAuto;
    if (posicion != null) result.posicion = posicion;
    return result;
  }

  TerminaViajeArgs._();

  factory TerminaViajeArgs.fromBuffer($core.List<$core.int> data, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromBuffer(data, registry);
  factory TerminaViajeArgs.fromJson($core.String json, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromJson(json, registry);

  static final $pb.BuilderInfo _i = $pb.BuilderInfo(_omitMessageNames ? '' : 'TerminaViajeArgs', package: const $pb.PackageName(_omitMessageNames ? '' : 'uber'), createEmptyInstance: create)
    ..a<$core.int>(1, _omitFieldNames ? '' : 'idAuto', $pb.PbFieldType.O3)
    ..aOM<Posicion>(2, _omitFieldNames ? '' : 'posicion', subBuilder: Posicion.create)
    ..hasRequiredFields = false
  ;

  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  TerminaViajeArgs clone() => TerminaViajeArgs()..mergeFromMessage(this);
  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  TerminaViajeArgs copyWith(void Function(TerminaViajeArgs) updates) => super.copyWith((message) => updates(message as TerminaViajeArgs)) as TerminaViajeArgs;

  @$core.override
  $pb.BuilderInfo get info_ => _i;

  @$core.pragma('dart2js:noInline')
  static TerminaViajeArgs create() => TerminaViajeArgs._();
  @$core.override
  TerminaViajeArgs createEmptyInstance() => create();
  static $pb.PbList<TerminaViajeArgs> createRepeated() => $pb.PbList<TerminaViajeArgs>();
  @$core.pragma('dart2js:noInline')
  static TerminaViajeArgs getDefault() => _defaultInstance ??= $pb.GeneratedMessage.$_defaultFor<TerminaViajeArgs>(create);
  static TerminaViajeArgs? _defaultInstance;

  @$pb.TagNumber(1)
  $core.int get idAuto => $_getIZ(0);
  @$pb.TagNumber(1)
  set idAuto($core.int value) => $_setSignedInt32(0, value);
  @$pb.TagNumber(1)
  $core.bool hasIdAuto() => $_has(0);
  @$pb.TagNumber(1)
  void clearIdAuto() => $_clearField(1);

  @$pb.TagNumber(2)
  Posicion get posicion => $_getN(1);
  @$pb.TagNumber(2)
  set posicion(Posicion value) => $_setField(2, value);
  @$pb.TagNumber(2)
  $core.bool hasPosicion() => $_has(1);
  @$pb.TagNumber(2)
  void clearPosicion() => $_clearField(2);
  @$pb.TagNumber(2)
  Posicion ensurePosicion() => $_ensure(1);
}

class InfoServicio extends $pb.GeneratedMessage {
  factory InfoServicio({
    $core.int? totalViajes,
    $core.Iterable<Auto>? autos,
  }) {
    final result = create();
    if (totalViajes != null) result.totalViajes = totalViajes;
    if (autos != null) result.autos.addAll(autos);
    return result;
  }

  InfoServicio._();

  factory InfoServicio.fromBuffer($core.List<$core.int> data, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromBuffer(data, registry);
  factory InfoServicio.fromJson($core.String json, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromJson(json, registry);

  static final $pb.BuilderInfo _i = $pb.BuilderInfo(_omitMessageNames ? '' : 'InfoServicio', package: const $pb.PackageName(_omitMessageNames ? '' : 'uber'), createEmptyInstance: create)
    ..a<$core.int>(1, _omitFieldNames ? '' : 'totalViajes', $pb.PbFieldType.O3)
    ..pc<Auto>(2, _omitFieldNames ? '' : 'autos', $pb.PbFieldType.PM, subBuilder: Auto.create)
    ..hasRequiredFields = false
  ;

  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  InfoServicio clone() => InfoServicio()..mergeFromMessage(this);
  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  InfoServicio copyWith(void Function(InfoServicio) updates) => super.copyWith((message) => updates(message as InfoServicio)) as InfoServicio;

  @$core.override
  $pb.BuilderInfo get info_ => _i;

  @$core.pragma('dart2js:noInline')
  static InfoServicio create() => InfoServicio._();
  @$core.override
  InfoServicio createEmptyInstance() => create();
  static $pb.PbList<InfoServicio> createRepeated() => $pb.PbList<InfoServicio>();
  @$core.pragma('dart2js:noInline')
  static InfoServicio getDefault() => _defaultInstance ??= $pb.GeneratedMessage.$_defaultFor<InfoServicio>(create);
  static InfoServicio? _defaultInstance;

  @$pb.TagNumber(1)
  $core.int get totalViajes => $_getIZ(0);
  @$pb.TagNumber(1)
  set totalViajes($core.int value) => $_setSignedInt32(0, value);
  @$pb.TagNumber(1)
  $core.bool hasTotalViajes() => $_has(0);
  @$pb.TagNumber(1)
  void clearTotalViajes() => $_clearField(1);

  @$pb.TagNumber(2)
  $pb.PbList<Auto> get autos => $_getList(1);
}

class Auto extends $pb.GeneratedMessage {
  factory Auto({
    $core.int? id,
    Posicion? posicion,
    $core.bool? disponible,
  }) {
    final result = create();
    if (id != null) result.id = id;
    if (posicion != null) result.posicion = posicion;
    if (disponible != null) result.disponible = disponible;
    return result;
  }

  Auto._();

  factory Auto.fromBuffer($core.List<$core.int> data, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromBuffer(data, registry);
  factory Auto.fromJson($core.String json, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromJson(json, registry);

  static final $pb.BuilderInfo _i = $pb.BuilderInfo(_omitMessageNames ? '' : 'Auto', package: const $pb.PackageName(_omitMessageNames ? '' : 'uber'), createEmptyInstance: create)
    ..a<$core.int>(1, _omitFieldNames ? '' : 'id', $pb.PbFieldType.O3)
    ..aOM<Posicion>(2, _omitFieldNames ? '' : 'posicion', subBuilder: Posicion.create)
    ..aOB(3, _omitFieldNames ? '' : 'disponible')
    ..hasRequiredFields = false
  ;

  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  Auto clone() => Auto()..mergeFromMessage(this);
  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  Auto copyWith(void Function(Auto) updates) => super.copyWith((message) => updates(message as Auto)) as Auto;

  @$core.override
  $pb.BuilderInfo get info_ => _i;

  @$core.pragma('dart2js:noInline')
  static Auto create() => Auto._();
  @$core.override
  Auto createEmptyInstance() => create();
  static $pb.PbList<Auto> createRepeated() => $pb.PbList<Auto>();
  @$core.pragma('dart2js:noInline')
  static Auto getDefault() => _defaultInstance ??= $pb.GeneratedMessage.$_defaultFor<Auto>(create);
  static Auto? _defaultInstance;

  @$pb.TagNumber(1)
  $core.int get id => $_getIZ(0);
  @$pb.TagNumber(1)
  set id($core.int value) => $_setSignedInt32(0, value);
  @$pb.TagNumber(1)
  $core.bool hasId() => $_has(0);
  @$pb.TagNumber(1)
  void clearId() => $_clearField(1);

  @$pb.TagNumber(2)
  Posicion get posicion => $_getN(1);
  @$pb.TagNumber(2)
  set posicion(Posicion value) => $_setField(2, value);
  @$pb.TagNumber(2)
  $core.bool hasPosicion() => $_has(1);
  @$pb.TagNumber(2)
  void clearPosicion() => $_clearField(2);
  @$pb.TagNumber(2)
  Posicion ensurePosicion() => $_ensure(1);

  @$pb.TagNumber(3)
  $core.bool get disponible => $_getBF(2);
  @$pb.TagNumber(3)
  set disponible($core.bool value) => $_setBool(2, value);
  @$pb.TagNumber(3)
  $core.bool hasDisponible() => $_has(2);
  @$pb.TagNumber(3)
  void clearDisponible() => $_clearField(3);
}

class ResultadoViaje extends $pb.GeneratedMessage {
  factory ResultadoViaje({
    $core.double? precio,
  }) {
    final result = create();
    if (precio != null) result.precio = precio;
    return result;
  }

  ResultadoViaje._();

  factory ResultadoViaje.fromBuffer($core.List<$core.int> data, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromBuffer(data, registry);
  factory ResultadoViaje.fromJson($core.String json, [$pb.ExtensionRegistry registry = $pb.ExtensionRegistry.EMPTY]) => create()..mergeFromJson(json, registry);

  static final $pb.BuilderInfo _i = $pb.BuilderInfo(_omitMessageNames ? '' : 'ResultadoViaje', package: const $pb.PackageName(_omitMessageNames ? '' : 'uber'), createEmptyInstance: create)
    ..a<$core.double>(1, _omitFieldNames ? '' : 'precio', $pb.PbFieldType.OD)
    ..hasRequiredFields = false
  ;

  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  ResultadoViaje clone() => ResultadoViaje()..mergeFromMessage(this);
  @$core.Deprecated('See https://github.com/google/protobuf.dart/issues/998.')
  ResultadoViaje copyWith(void Function(ResultadoViaje) updates) => super.copyWith((message) => updates(message as ResultadoViaje)) as ResultadoViaje;

  @$core.override
  $pb.BuilderInfo get info_ => _i;

  @$core.pragma('dart2js:noInline')
  static ResultadoViaje create() => ResultadoViaje._();
  @$core.override
  ResultadoViaje createEmptyInstance() => create();
  static $pb.PbList<ResultadoViaje> createRepeated() => $pb.PbList<ResultadoViaje>();
  @$core.pragma('dart2js:noInline')
  static ResultadoViaje getDefault() => _defaultInstance ??= $pb.GeneratedMessage.$_defaultFor<ResultadoViaje>(create);
  static ResultadoViaje? _defaultInstance;

  @$pb.TagNumber(1)
  $core.double get precio => $_getN(0);
  @$pb.TagNumber(1)
  set precio($core.double value) => $_setDouble(0, value);
  @$pb.TagNumber(1)
  $core.bool hasPrecio() => $_has(0);
  @$pb.TagNumber(1)
  void clearPrecio() => $_clearField(1);
}


const $core.bool _omitFieldNames = $core.bool.fromEnvironment('protobuf.omit_field_names');
const $core.bool _omitMessageNames = $core.bool.fromEnvironment('protobuf.omit_message_names');
