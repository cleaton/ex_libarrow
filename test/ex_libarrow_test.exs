defmodule ExLibarrowTest do
  use ExUnit.Case
  doctest ExLibarrow

  test "greets the world" do
    assert ExLibarrow.hello() == :world
  end
end
