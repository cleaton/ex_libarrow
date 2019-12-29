defmodule ExLibarrowTest do
  use ExUnit.Case
  doctest ExLibarrow

  test "Can build schema" do
    schema = [
      {"int", :int32},
      {"str下", :utf8}
    ]
    {:ok, ref} = ExLibarrow.build_schema(schema)

    :ok = ExLibarrow.print_schema(ref)
  end
end
