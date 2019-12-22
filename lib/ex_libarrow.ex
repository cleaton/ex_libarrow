defmodule ExLibarrow do
  @moduledoc """
  Documentation for ExLibarrow.
  """
  @on_load :load_nifs

  def load_nifs do
    :ok = :erlang.load_nif('./ex_libarrow', 0)
  end

  @doc """
  Hello world.

  ## Examples

      iex> ExLibarrow.hello()
      :world

  """
  def add(_a, _b) do
    raise "NIF add/2 not implemented"
  end
end
