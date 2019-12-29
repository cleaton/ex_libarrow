defmodule ExLibarrow do
  @moduledoc """
  Documentation for ExLibarrow.
  """
  @on_load :load_nifs

  def load_nifs do
    :ok = :erlang.load_nif('./ex_libarrow', 0)
  end

  def add(_a, _b) do
    raise "NIF add/2 not implemented"
  end

  def build_schema(_a) do
    raise "NIF build_schema/1 not implemented"
  end

  def print_schema(_a) do
    raise "NIF build_schema/1 not implemented"
  end
end
